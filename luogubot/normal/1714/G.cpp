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
const int N=4e5+10;
int head[N],to[N],nxt[N],val1[N],val2[N],cnt;
void add(int u,int v,int w1,int w2){
	to[++cnt]=v,val1[cnt]=w1,val2[cnt]=w2,nxt[cnt]=head[u],head[u]=cnt;
}int n,A[N],R[N];
void dfs1(int u){
	go(u){
		int v=to[i];
		A[v]=A[u]+val1[i];
		dfs1(v);
	}
}
int stk[N],tp;
void dfs2(int u,int now){
	stk[++tp]=now;
	stk[++tp]=1e18;
	R[u]=upper_bound(stk+1,stk+1+tp,A[u])-stk-2;
	tp--;
	go(u){
		int v=to[i];
		dfs2(v,now+val2[i]);
	}
	tp--;
}
signed main(){
	int T=read();while(T--){
		n=read();For(i,1,n)head[i]=0;cnt=0;
		For(i,2,n){
			int j=read(),w1=read(),w2=read();
			add(j,i,w1,w2);
		}dfs1(1),dfs2(1,0);For(i,2,n)printf("%lld ",R[i]);puts("");
	}
	return 0;
}