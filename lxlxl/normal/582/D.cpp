#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

const ll maxn = 5100;
const ll Mod = 1e9+7;

char str[maxn]; ll len;
ll s[maxn];
ll p; ll k;

ll t[maxn]; ll tp;
void divide()
{
	ll now=0;
	for(ll i=len;i>=1;i--)
	{
		now=now*10+s[i];
		s[i]=now/p; now%=p;
	}
	t[++tp]=now;
	ll tl=len; len=0;
	for(ll i=tl;i>=1;i--) if(s[i]) { len=i; break; }
}
//           up next
ll f[2][maxn][2][2];

ll Cal(ll r){return (1ll+r)*r/2%Mod;}
ll solve()
{
	if(tp<k) return 0;
	ll now=0;
	f[now][0][1][0]=1ll;
	for(ll i=tp;i>=1;i--)
	{
		now=!now; memset(f[now],0,sizeof f[now]);
		for(ll j=0;j<=tp-i;j++)
		{
			(f[now][j][0][0]+=f[!now][j][0][0]*Cal(p)%Mod)%=Mod;
			(f[now][j][0][1]+=f[!now][j][0][0]*Cal(p-1)%Mod)%=Mod;
			
			(f[now][j+1][0][0]+=f[!now][j][0][1]*Cal(p-1)%Mod)%=Mod;
			(f[now][j+1][0][1]+=f[!now][j][0][1]*Cal(p)%Mod)%=Mod;
			
			(f[now][j][0][0]+=f[!now][j][1][0]*Cal(t[i])%Mod)%=Mod;
			(f[now][j][0][1]+=f[!now][j][1][0]*Cal(t[i]-1)%Mod)%=Mod;
			
			(f[now][j][1][0]+=f[!now][j][1][0]*(t[i]+1)%Mod)%=Mod;
			(f[now][j][1][1]+=f[!now][j][1][0]*t[i]%Mod)%=Mod;
			
			(f[now][j+1][0][0]+=f[!now][j][1][1]*((t[i]*(p-t[i])%Mod+Cal(t[i]-1))%Mod)%Mod)%=Mod;
			(f[now][j+1][0][1]+=f[!now][j][1][1]*((t[i]*(p+1-t[i])+Cal(t[i]-1))%Mod)%Mod)%=Mod;
			
			(f[now][j+1][1][0]+=f[!now][j][1][1]*(p-1-t[i])%Mod)%=Mod;
			(f[now][j+1][1][1]+=f[!now][j][1][1]*(p-t[i])%Mod)%=Mod;
		}
	}
	ll re=0;
	for(ll i=k;i<=tp;i++) (re+=f[now][i][0][0]+f[now][i][1][0])%=Mod;
	return re;
}

int main()
{
	scanf("%I64d%I64d",&p,&k);
	scanf("%s",str); len=strlen(str);
	for(ll i=0;i<len;i++) s[len-i]=str[i]-'0';
	
	while(len) divide();
	
	printf("%I64d\n",solve());
	
	return 0;
}