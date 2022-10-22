#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=155;
int n,m;
struct edge{
	int u,v,w;
	bool operator < (const edge &x) const {
		return w<x.w;
	}
}e[N];
struct matrix{
	bitset<N> a[N];
	matrix(){For(i,0,N-1)a[i].reset();}
	void init(){For(i,1,n)a[i].reset();}
	void init1(){init();For(i,1,n)a[i][i]=1;}
	matrix operator * (const matrix &x) const {
		matrix c;//c[i][j]= or (a[i][k] and b[k][j])
		For(i,1,n)For(k,1,n)if(a[i][k])c.a[i]|=x.a[k];
		return c;
	}
}A,E;
matrix qpow(matrix a,int b){
	matrix x;x.init1();
	while(b){
		if(b&1)x=x*a;
		a=a*a,b>>=1;
	}return x;
}
int dis[N];vector<int> g[N];
queue<int> q;
void bfs(int lim){
	For(i,1,n)g[i].clear(),dis[i]=1e18;
	For(i,1,lim)g[e[i].v].push_back(e[i].u);
	dis[n]=0;q.push(n);while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u])if(dis[u]+1<dis[v])dis[v]=dis[u]+1,q.push(v);
	}
}
signed main(){
	n=read(),m=read();For(i,1,m)e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+1+m),A.a[1][1]=1;int lst=0,ans=1e18;
	For(i,1,m){
		A=A*qpow(E,e[i].w-lst),lst=e[i].w,E.a[e[i].u][e[i].v]=1;
		bfs(i);For(u,1,n)if(A.a[1][u])ans=min(ans,lst+dis[u]);
		if(lst>ans)break;
	}if(ans<1e18)cout<<ans;else puts("Impossible");
	return 0;
}