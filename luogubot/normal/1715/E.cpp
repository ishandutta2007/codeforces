#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
#define db double
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10,K=21,inf=1e11;
int f[K][N],n,m,k,U[N],V[N],W[N];
inline void gmin(int &a,int b){(a>b)&&(a=b);}
struct line{
	int x,y;
	inline int val(int k){return y-k*x;}
}q[N];
bool check(line A,line B,line C){
	return (B.y-A.y)*(C.x-B.x)<(C.y-B.y)*(B.x-A.x);
}
struct node{
	int u,w;
	bool operator < (const node &x) const {return w>x.w;}
};priority_queue<node> Q;int vis[N];
int head[N],to[N],nxt[N],val[N],cnt;
void add(int u,int v,int w){
	to[++cnt]=v,val[cnt]=w,nxt[cnt]=head[u],head[u]=cnt;
}
void dij(int *dis){
	For(i,1,n)Q.push((node){i,dis[i]}),vis[i]=0;while(!Q.empty()){
		int u=Q.top().u;Q.pop();if(vis[u])continue;vis[u]=1;
		go(u){
			int v=to[i],w=val[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w,Q.push((node){v,dis[v]});
			}
		}
	}
}
void solve(int* f,int* g){
	For(i,1,n)f[i]=g[i];
	int L=1,R=0;For(i,1,n){
		line p=(line){i,g[i]+i*i};
		while(L<R&&!check(q[R-1],q[R],p))R--;
		q[++R]=p;
	}
	For(i,1,n){
		while(L<R&&q[L].val(2*i)>q[L+1].val(2*i))L++;
		gmin(f[i],i*i+q[L].val(2*i));
	}dij(f);
}
signed main(){
	n=read(),m=read(),k=read();For(i,1,m){int u=read(),v=read(),w=read();add(u,v,w),add(v,u,w);}
	For(i,1,n)f[0][i]=inf;f[0][1]=0;dij(f[0]);
	For(i,1,k)solve(f[i],f[i-1]);For(i,1,n)printf("%lld ",f[k][i]);
	return 0;
}