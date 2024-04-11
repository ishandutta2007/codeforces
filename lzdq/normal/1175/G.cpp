#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
typedef long long ll;
const int MAXN=2e4+5,INF=0x3f3f3f3f;
int n,k,a[MAXN];
int rt,lc[MAXN],rc[MAXN];
int top,stk[MAXN];
int f[MAXN],g[MAXN],mi[MAXN];
deque<int> que[MAXN];
int siz[MAXN];
void Dfs(int u){
	siz[u]=1;
	if(lc[u]){
		Dfs(lc[u]);
		siz[u]+=siz[lc[u]];
	}
	if(rc[u]){
		Dfs(rc[u]);
		siz[u]+=siz[rc[u]];
	}
	return ;
}
inline double getk(int a,int b){
	return (double)(f[b-1]-f[a-1])/(b-a);
}
void Dfs1(int u){
	que[u].clear();
	if(lc[u]) Dfs1(lc[u]);
	swap(que[u],que[lc[u]]);
	if(f[u-1]<INF){
		while(que[u].size()>=2&&getk(que[u][que[u].size()-2],que[u].back())>=getk(que[u].back(),u)) que[u].pop_back();
		que[u].push_back(u);
	}
	if(!que[u].empty()){
		int l=0,r=que[u].size()-1;
		while(l<r){
			int mid=l+r>>1;
			if(getk(que[u][mid],que[u][mid+1])>a[u]) r=mid;
			else l=mid+1;
		}
		mi[u]=f[que[u][l]-1]+a[u]*(1-que[u][l]);
	}
	if(rc[u]) Dfs1(rc[u]);
	if(que[u].size()<que[rc[u]].size()){
		while(!que[u].empty()){
			int x=que[u].back();
			que[u].pop_back();
			while(que[rc[u]].size()>=2&&getk(x,que[rc[u]].front())>=getk(que[rc[u]].front(),que[rc[u]][1])) que[rc[u]].pop_front();
			que[rc[u]].push_front(x);
		}
		swap(que[u],que[rc[u]]);
	}else{
		while(!que[rc[u]].empty()){
			int x=que[rc[u]].front();
			que[rc[u]].pop_front();
			while(que[u].size()>=2&&getk(que[u][que[u].size()-2],que[u].back())>=getk(que[u].back(),x)) que[u].pop_back();
			que[u].push_back(x);
		}
	}
	return ;
}
int dat[MAXN<<2][2];
struct Mod{
	int *x,y;
}mods[MAXN*100];
inline void Mods(int &x,int y){
	if(x!=y){
		mods[++top]=Mod{&x,x};
		x=y;
	}
}
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
void Modify(int k,int l,int r,int a0,int a1){
	bool p(a0+a1*l<=dat[k][0]+dat[k][1]*l),q(a0+a1*r<=dat[k][0]+dat[k][1]*r);
	if(!dat[k][1] ||  p&&q ){
		Mods(dat[k][0],a0);
		Mods(dat[k][1],a1);
		return ;
	}
	if(l==r || !p&&!q) return ;
	int mid=l+r>>1;
	if(a0+a1*mid<=dat[k][0]+dat[k][1]*mid){
		mods[++top]=Mod{dat[k],dat[k][0]};
		mods[++top]=Mod{dat[k]+1,dat[k][1]};
		swap(dat[k][0],a0);
		swap(dat[k][1],a1);
		p^=1;
		q^=1;
	}
	if(p) Modify(ls,a0,a1);
	else Modify(rs,a0,a1);
	return ;
}
int Query(int k,int l,int r,int x){
	int res=INF;
	if(dat[k][1]) res=x*dat[k][1]+dat[k][0];
	if(l==r) return res;
	int mid=l+r>>1;
	if(x<=mid) res=min(res,Query(ls,x));
	else res=min(res,Query(rs,x));
	return res;
}
#undef lc
#undef rc
#undef ls
#undef rs
void Dfs2(int u){
	if(lc[u]) Dfs2(lc[u]);
	int _top=top;
	if(mi[u]<INF) Modify(1,1,n,mi[u],a[u]);
	g[u]=Query(1,1,n,u);
	if(rc[u]) Dfs2(rc[u]);
	while(top>_top){
		*mods[top].x=mods[top].y;
		top--;
	}
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",a+i);
		while(top&&a[stk[top]]<=a[i]){
			rc[stk[top]]=lc[i];
			lc[i]=stk[top--];
		}
		stk[++top]=i;
	}
	while(top){
		rc[stk[top]]=rt;
		rt=stk[top--];
	}
	Dfs(rt);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	while(k--){
		memset(mi,0x3f,sizeof(mi));
		Dfs1(rt);
		g[0]=INF;
		Dfs2(rt);
		memcpy(f,g,sizeof(f));
	}
	printf("%d\n",f[n]);
	return 0;
}