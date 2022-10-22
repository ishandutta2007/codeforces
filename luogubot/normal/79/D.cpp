// LUOGU_RID: 90461731
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e4+10;
int n,k,l,m,a[N],b[N],len[N],d[N],pos[50],c[50][50];
vector<int> g[N];int f[1<<20];queue<int> q;
inline void gmin(int &a,int b){(a>b)&&(a=b);}
void bfs(int id){
	memset(d,0x3f,sizeof d),d[pos[id]]=0,q.push(pos[id]);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u])if(d[v]>d[u]+1)d[v]=d[u]+1,q.push(v);
	}For(i,0,m-1)c[id][i]=d[pos[i]];
}
signed main(){
	n=read(),k=read(),l=read();For(i,1,k)a[read()]=1;
	Rof(i,n+1,1)a[i]^=a[i-1];
	For(i,1,l)len[i]=read();For(i,1,n+1)For(j,1,l){
		if(i+len[j]<=n+1)g[i].push_back(i+len[j]);
		if(i-len[j]>=1)g[i].push_back(i-len[j]);
	}For(i,1,n+1)if(a[i])pos[m++]=i;For(i,0,m-1)bfs(i);
	memset(f,0x3f,sizeof f);f[(1<<m)-1]=0;
	Rof(S,(1<<m)-1,1)if(__builtin_popcount(S)%2==0){
		int u=__builtin_ctz(S);For(v,u+1,m-1)if(S>>v&1)
			gmin(f[S^(1<<u)^(1<<v)],f[S]+c[u][v]);
	}cout<<(f[0]<1e9?f[0]:-1)<<endl;
	return 0;
}