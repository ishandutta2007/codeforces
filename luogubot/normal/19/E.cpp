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
bool ST;
const int N=2e4+10;
int n,m;
int head[N],to[N],nxt[N],num[N],cnt;
void add(int u,int v,int id){
	to[++cnt]=v,num[cnt]=id,nxt[cnt]=head[u],head[u]=cnt;
}int vis[N],cur[N],vise[N],neid,a[N],tot;
void dfs(int u){
	vis[u]=1;go(u){
		int v=to[i],id=num[i];
		if(!vis[v])cur[v]=cur[u]^1,vise[id]=1,dfs(v);
		else if(!vise[id]){
			vise[id]=1;
			if(cur[u]==cur[v])a[u]++,a[v]--,neid=id,tot++;// 
			else a[u]--,a[v]++;// 
		}
	}
}
vector<int> ans;
void solve(int u){
	vis[u]=1;go(u){
		int v=to[i];
		if(!vis[v]){
			solve(v),a[u]+=a[v];
			if(a[v]==tot)ans.push_back(num[i]);
		}
	}
}
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	n=read(),m=read();For(i,1,m){
		int u=read(),v=read();add(u,v,i),add(v,u,i);
	}For(i,1,n)if(!vis[i])dfs(i);if(!tot){printf("%d\n",m);For(i,1,m)printf("%d ",i);return 0;}
	memset(vis,0,sizeof vis);For(i,1,n)if(!vis[i])solve(i);if(tot==1)ans.push_back(neid);
	sort(ans.begin(),ans.end());printf("%d\n",ans.size());for(int v:ans)printf("%d ",v);puts("");
	return 0;
}