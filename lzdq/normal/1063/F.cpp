#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=5e5+5,MAXM=2e7;
struct Sam{
	int ch[26],len,fa;
}dat[MAXN<<1];
int cntp,las;
int Extend(int c){
	int p=las;
	int np=las=++cntp;
	dat[np].len=dat[p].len+1;
	while(p&&!dat[p].ch[c])
		dat[p].ch[c]=np,p=dat[p].fa;
	if(dat[p].ch[c]){
		int q=dat[p].ch[c];
		if(dat[q].len>dat[p].len+1){
			int nq=++cntp;
			dat[nq]=dat[q];
			dat[nq].len=dat[p].len+1;
			dat[q].fa=dat[np].fa=nq;
			while(p&&dat[p].ch[c]==q)
				dat[p].ch[c]=nq,p=dat[p].fa;
		}else dat[np].fa=q;
	}else dat[np].fa=1;
	return np;
}
int cnte,h[MAXN<<1],nx[MAXN<<1],to[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int cnts,rt[MAXN<<1];
int lc[MAXM],rc[MAXM];
#define ls lc[k],l,mid
#define rs rc[k],mid+1,r
void Build(int &k,int l,int r,int w){
	k=++cnts;
	if(l==r) return ;
	int mid=l+r>>1;
	if(w<=mid) Build(ls,w);
	else Build(rs,w);
	return ;
}
int Merge(int u,int v){
	if(!u||!v) return u+v;
	int k=++cnts;
	lc[k]=Merge(lc[u],lc[v]);
	rc[k]=Merge(rc[u],rc[v]);
	return k;
}
int Query(int k,int l,int r,int w){
	if(!k||r<w) return 0;
	if(l==r) return l;
	int mid=l+r>>1,res=Query(ls,w);
	if(!res) res=Query(rs,w);
	return res;
}
void Dfs(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		Dfs(v);
		rt[u]=Merge(rt[u],rt[v]);
	}
	return ;
}
int n;
char s[MAXN];
int f[MAXN];
bool Check(int k){
	for(int i=k; i<=n; i++)
		f[i]=k;
	int l=1,r=0,p=1,mx=0;
	for(int i=k; i<=n; i++){
		//printf("%d f %d\n",i,f[i]);
		if(f[i]==1) return 1;
		l=i-f[i]+1;
		if(l<=mx) continue;
		mx=l;
		while(r<i-1) p=dat[p].ch[s[++r]];
		while(dat[dat[p].fa].len>=r-l+1) p=dat[p].fa;
		int w=Query(rt[p],1,n,i+f[i]-1);
		//printf("mxl p %d\n",dat[p].len);
		if(w) f[w]=min(f[w],f[i]-1);
		int q=dat[p].ch[s[i]];
		if(dat[dat[q].fa].len>=f[i]-1) q=dat[q].fa;
		//printf("mxl q %d\n",dat[q].len);
		w=Query(rt[q],1,n,i+f[i]-1);
		if(w) f[w]=min(f[w],f[i]-1);
	}
	return 0;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	scanf("%s",s+1);
	las=cntp=1;
	for(int i=1; i<=n; i++)
		Build(rt[Extend(s[i]-='a')],1,n,i);
	for(int i=2; i<=cntp; i++)
		adde(dat[i].fa,i);
	Dfs(1);
	//Check(3); return 0;
	int l=1,r=1005;
	while(l<r){
		int mid=l+r+1>>1;
		if(Check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}