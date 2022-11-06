#include<bits/stdc++.h>
#define N 200005
using namespace std;

int n,m,cnt,pt,bin[25],lg2[N],fst[N],nxt[N],sa[N],sum[N],rnk[N<<1],q[N<<1],f[18][N],g[18][N],ans[N];
char s[N];
struct node{ int l,r,x,y; }op[N];
void getsa(){
	int i,j,k;
	for (i=1; i<=n; i++) sum[s[i]-'a']++;
	for (i=1; i<26; i++) sum[i]+=sum[i-1];
	for (i=n; i; i--) sa[sum[s[i]-'a']--]=i;
	for (i=1,cnt=0; i<=n; rnk[sa[i++]]=cnt)
		if (i==1 || s[sa[i]]!=s[sa[i-1]]) cnt++;
	for (k=1; cnt<n; k<<=1){
		for (i=1; i<=k; i++) q[i]=n-k+i;
		for (i=1,j=k; i<=n; i++) if (sa[i]>k) q[++j]=sa[i]-k;
		memset(sum,0,sizeof(sum));
		for (i=1; i<=n; i++) sum[rnk[i]]++;
		for (i=2; i<=cnt; i++) sum[i]+=sum[i-1];
		for (i=n; i; i--) sa[sum[rnk[q[i]]]--]=q[i];
		for (i=1,cnt=0; i<=n; q[sa[i++]]=cnt)
			if (i==1 || rnk[sa[i]]!=rnk[sa[i-1]] || rnk[sa[i]+k]!=rnk[sa[i-1]+k]) cnt++;
		swap(rnk,q);
	}
}
void gethgt(){
	int i,j,k=0;
	for (i=1; i<=n; i++){
		if (k) k--; j=sa[rnk[i]-1];
		for (; i+k<=n && j+k<=n && s[i+k]==s[j+k]; k++);
		f[0][rnk[i]]=k;
	}
}
int rmq(int f[][N],int x,int y){
	if (x>y) swap(x,y);
	int k=lg2[y-x+1];
	return min(f[k][x],f[k][y-bin[k]+1]);
}
void build(int f[][N],int n){
	int i,j;
	for (i=1; i<=17; i++)
		for (j=0; j<=n; j++){
			f[i][j]=f[i-1][j];
			if (j+bin[i-1]<=n) f[i][j]=min(f[i][j],f[i-1][j+bin[i-1]]);
		}
}
int lcp(int x,int y){
	if (x==y) return n-x+1;
	x=rnk[x]; y=rnk[y];
	if (x>y) swap(x,y); return rmq(f,x+1,y);
}
int bj(int x,int y,int l){
	if (lcp(x,y)>=l) return 0; else return (rnk[x]<rnk[y])?-1:1;
}
bool cmp(int x,int y){
	bool flag=(x>y); int t; if (x>y) swap(x,y);
	if (x+n-m<=y){
		t=bj(m+1,x+1,n-m);
		if (t) return (t<0)^flag;
		t=bj(x+1,x+n-m+1,y-(x+n-m));
		if (t) return (t<0)^flag;
		t=bj(y-(n-m)+1,m+1,n-m);
		if (t) return (t<0)^flag;
	} else{
		t=bj(m+1,x+1,y-x);
		if (t) return (t<0)^flag;
		t=bj(m+y-x+1,m+1,x+n-m-y);
		if (t) return (t<0)^flag;
		t=bj(x+1,n+x-y+1,y-x);
		if (t) return (t<0)^flag;
	}
	return (x<y)^flag;
}
int main(){
	scanf("%s",s+1); m=strlen(s+1);
	scanf("%s%d",s+m+1,&pt); n=strlen(s+1);
	int i,j,k,x,y;
	getsa(); gethgt();
	bin[0]=1; for (i=1; i<=17; i++) bin[i]=bin[i-1]<<1;
	for (i=2; i<=n; i++) lg2[i]=lg2[i>>1]+1;
	build(f,n);
	for (i=0; i<=m; i++) q[i]=i;
	sort(q,q+m+1,cmp);
	for (i=0; i<=m; i++) f[0][q[i]]=i; q[m+1]=-1;
	build(f,m);
	for (i=1; i<=pt; i++){
		scanf("%d%d%d%d%d",&op[i].l,&op[i].r,&j,&op[i].x,&op[i].y);
		nxt[i]=fst[j]; fst[j]=i;
		ans[i]=m+1;
	}
	for (i=1; i<=m; i++)
		if (fst[i] && i<=80)
			for (j=0; j<i; j++){
				for (k=0; i*k+j<=m; k++) g[0][k]=f[0][i*k+j];
				build(g,k-1);
				for (k=fst[i]; k; k=nxt[k]) if (op[k].x<=j && j<=op[k].y){
					x=(op[k].l-j)/i; if (x*i+j<op[k].l) x++;
					y=(op[k].r-j)/i; if (y*i+j>op[k].r) y--;
					if (x<=y) ans[k]=min(ans[k],rmq(g,x,y));
				}
			}
		else
			for (j=fst[i]; j; j=nxt[j])
				for (k=0; k*i<=m; k++){
					x=max(k*i+op[j].x,op[j].l); y=min(k*i+op[j].y,op[j].r);
					if (x<=y) ans[j]=min(ans[j],rmq(f,x,y));
				}
	for (i=1; i<=pt; i++) printf("%d%c",q[ans[i]],(i<pt)?' ':'\n');
	return 0;
}