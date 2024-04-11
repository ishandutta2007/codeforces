#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
//#define int long long 
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e5+10;
int head[N],to[N],nxt[N],cnt=1;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int p,n,a[N],b[N],idx,dep[N];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	go(u){
		int v=to[i];if(v==f)continue;
		b[i>>1]=n+idx,a[v]=idx,idx++;
		if(dep[u]%2==0)swap(b[i>>1],a[v]);
		dfs(v,u);
	}
}
signed main(){
	int T=read();while(T--){
		p=read(),n=1<<p;For(i,1,n)head[i]=0;cnt=1;idx=1;
		For(i,2,n){int u=read(),v=read();add(u,v),add(v,u);}
		puts("1"),a[1]=n,dfs(1,0);For(i,1,n)printf("%d ",a[i]);puts("");
		For(i,1,n-1)printf("%d ",b[i]);puts("");
	} 
	return 0;
}