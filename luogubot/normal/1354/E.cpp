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
const int N=5e3+10,M=2e5+10;
int head[N],to[M],nxt[M],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int n,m,n1,n2,n3,col[N],vis[N],fl=1,k;
int a[N],b[N],f[N],pre[N][N],g[N],cur[N];
vector<int> s1[N],s2[N];
void dfs(int u){
	if(col[u])a[k]++,s1[k].push_back(u);else b[k]++,s2[k].push_back(u);
	vis[u]=1;go(u){
		int v=to[i];
		if(vis[v])fl&=col[u]!=col[v];
		else col[v]=col[u]^1,dfs(v);
	}
}
signed main(){
	n=read(),m=read();
	n1=read(),n2=read(),n3=read();
	For(i,1,m){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}For(i,1,n)if(!vis[i]){
		k++,dfs(i);
	}if(!fl)return puts("NO"),0;
	f[0]=1;For(j,1,k){
		Rof(i,n,a[j]){
			if(f[i-a[j]]&&!g[i])g[i]=1,pre[j][i]=0;
		}
		Rof(i,n,b[j]){
			if(f[i-b[j]]&&!g[i])g[i]=1,pre[j][i]=1;
		}
		For(i,0,n)f[i]=g[i],g[i]=0;
	}if(!f[n2])return puts("NO"),0;
	int x=n2;Rof(i,k,1){
		int id=i,s=pre[i][x];
		if(s==1)x-=b[id];
		else x-=a[id];
		if(s==1){
			for(auto u:s2[id])cur[u]=2;
			for(auto u:s1[id])if(n1)cur[u]=1,n1--;else cur[u]=3;
		}else{
			for(auto u:s1[id])cur[u]=2;
			for(auto u:s2[id])if(n1)cur[u]=1,n1--;else cur[u]=3;
		}
	}puts("YES");For(i,1,n)printf("%d",cur[i]);
	return 0;
}//dsadsa