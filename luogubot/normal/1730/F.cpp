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
const int N=5e3+10;
int n,k,p[N],q[N],dp[N][1<<8],c[N];
#define lowbit(x) (x&-x)
inline void add(int u,int v){for(int i=u;i;i-=lowbit(i))c[i]+=v;}
inline int ask(int u,int s=0){for(int i=u;i<=n;i+=lowbit(i))s+=c[i];return s;}
inline void gmin(int &a,int b){(a>b)&&(a=b);}
signed main(){
	n=read(),k=read();For(i,1,n)q[p[i]=read()]=i;
	memset(dp,0x3f,sizeof dp),dp[1][0]=0;
	For(i,1,n){
		For(S,0,(1<<k)-1)if(dp[i][S]<=n*n){
			For(x,1,k)if(!(S>>x-1&1)&&i+x<=n){
				int add=ask(q[i+x]);
				For(y,1,k)if((S>>y-1&1)&&q[i+y]>q[i+x])add++;
				gmin(dp[i][S^(1<<x-1)],dp[i][S]+add);
			}
			int add=ask(q[i]);
			For(y,1,k)if((S>>y-1&1)&&q[i+y]>q[i])add++;
			int now=1;while(now<=k&&(S>>now-1&1))now++;
			gmin(dp[i+now][S>>now],dp[i][S]+add);
		}add(q[i],1);
	}cout<<dp[n+1][0]<<endl;
	return 0;
}