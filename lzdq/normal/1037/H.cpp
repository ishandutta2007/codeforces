#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5,MAXM=MAXN*3,MAXP=2e7;
int n,q;
char s[MAXN],t[MAXM];
struct node{
	int len,fa,ch[26];
}dat[MAXM];
int cntp,las;
int cnts,rt[MAXM],sum[MAXP],lc[MAXP],rc[MAXP];
#define ls lc[k],l,mid
#define rs rc[k],mid+1,r
void Build(int &k,int l,int r,int w){
	k=++cnts;
	sum[k]=1;
	if(l==r) return ;
	int mid=l+r>>1;
	if(w<=mid) Build(ls,w);
	else Build(rs,w);
	return ;
}
void Ins(int c,int id){
	c-='a';
	int p=las;
	int np=las=++cntp;
	dat[np].len=dat[p].len+1;
	while(!dat[p].ch[c])
		dat[p].ch[c]=np,p=dat[p].fa;
	if(p){
		int q=dat[p].ch[c];
		if(dat[q].len>dat[p].len+1){
			int nq=++cntp;
			dat[nq]=dat[q];
			dat[nq].len=dat[p].len+1;
			dat[q].fa=dat[np].fa=nq;
			while(dat[p].ch[c]==q)
				dat[p].ch[c]=nq,p=dat[p].fa;
		}else dat[np].fa=q;
	}else dat[np].fa=1;
	Build(rt[np],1,n,id);
}
int cnte,h[MAXM],nx[MAXM],to[MAXM];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int Query(int k,int l,int r,int x,int y){
	if(!k) return 0;
	if(x<=l&&r<=y) return sum[k];
	int mid=l+r>>1;
	if(x<=mid&&Query(ls,x,y)) return 1;
	return mid<y&&Query(rs,x,y);
}
int Merge(int k,int p,int l,int r){
	if(!k||!p) return k+p;
	int u=++cnts;
	sum[u]=sum[k]|sum[p];
	if(l==r) return u;
	int mid=l+r>>1;
	lc[u]=Merge(lc[k],lc[p],l,mid);
	rc[u]=Merge(rc[k],rc[p],mid+1,r);
	return u;
}
void Dfs(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		Dfs(v);
		rt[u]=Merge(rt[u],rt[v],1,n);
	}
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	cntp=las=1;
	for(int i=1; i<=n; i++)
		Ins(s[i],i);
	for(int i=2; i<=cntp; i++)
		adde(dat[i].fa,i);
	Dfs(1);
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		scanf("%s",t+1);
		static int p[MAXM];
		p[0]=1;
		int lcp=0;
		for(int i=1; t[i]; i++){
			p[i]=dat[p[i-1]].ch[t[i]-'a'];
			if(!p[i]) break;
			lcp=i;
		}
		bool ans=0;
		//printf("lcp %d\n",lcp);
		for(int i=lcp; i>=0; i--){	// lcp
			for(int j=max(0,t[i+1]-'a'+1); j<26; j++)
				if(l+i<=r&&Query(rt[dat[p[i]].ch[j]],1,n,l+i,r)){
					for(int k=1; k<=i; k++) putchar(t[k]);
					printf("%c\n",j+'a');
					ans=1;
					break;
				}
			if(ans) break;
		}
		if(!ans) puts("-1");
	}
	return 0;
}