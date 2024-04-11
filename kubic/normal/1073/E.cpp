#include <bits/stdc++.h>
using namespace std;
#define N 25
#define STT 1<<10
#define MOD 998244353
#define ll long long
#define set(a,v) memset(a,v,sizeof(a))
int n,a[N],pw[N],c[STT];ll L,R;
struct node
{
	int x,y;
	node(int _x=0,int _y=0) {x=_x;y=_y;}
}dp[N][STT];
node dfs(int u,bool lim,bool ld,int stt)
{
	if(ld) stt=0;if(c[stt]>n) return node();if(!u) return !ld;
	if(!lim && !ld && ~dp[u][stt].x) return dp[u][stt];
	int up=lim?a[u]:9;node t,res;
	for(int i=0;i<=up;++i)
	{
		t=dfs(u-1,lim&(i==up),ld&(!i),stt|(1<<i));
		res.x=(res.x+t.x)%MOD;
		res.y=((res.y+t.y)%MOD+1ll*i*pw[u-1]%MOD*t.x%MOD)%MOD;
	}if(!lim && !ld) dp[u][stt]=res;return res;
}
int slv(ll x)
{
	a[0]=0;for(;x;x/=10) a[++a[0]]=x%10;
	return dfs(a[0],1,1,0).y;
}
int main()
{
	set(dp,-1);scanf("%lld %lld %d",&L,&R,&n);
	pw[0]=1;for(int i=1;i<=20;++i) pw[i]=1ll*pw[i-1]*10%MOD; 
	for(int i=1;i<(1<<10);++i) c[i]=c[i&i-1]+1;
	printf("%d\n",(slv(R)-slv(L-1)+MOD)%MOD);return 0;
}