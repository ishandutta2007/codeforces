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
using namespace std;

const int maxn = 60;
const ll Mod = 1e9+7;

ll pw(ll x,int k)
{
	ll re=1ll;
	for(;k;k>>=1,x=x*x%Mod)
		if(k&1) (re*=x)%=Mod;
	return re;
}
int n,m;
ll inv[maxn];
ll f[maxn][maxn],g[maxn][maxn],h[maxn][maxn];


int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<maxn;i++) inv[i]=pw(i,Mod-2);
	
	f[0][1]=1ll;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int a=0;a<=i-1;a++)
			{
				int c=i-1-a;
				for(int b=j;b<=a+1;b++) g[i][j]+=f[a][b]*f[c][j]%Mod;
				for(int d=j+1;d<=c+1;d++) g[i][j]+=f[a][j]*f[c][d]%Mod;
			}
			g[i][j]%=Mod;
			
			for(int p=0;p<=n-i;p++)
			{
				for(int q=1;q<=p+1;q++)
				{
					ll tmp=f[p][q];
					if(!tmp) continue;
					for(int t=1;p+i*t<=n;t++)
					{
						tmp=tmp*(g[i][j]+t-1)%Mod*inv[t]%Mod;
						h[p+i*t][q+j*t]+=tmp;
					}
				}
			}
			for(int p=0;p<=n;p++) for(int q=0;q<=p+1;q++) (f[p][q]+=h[p][q]%Mod)%=Mod,h[p][q]=0;
		}
	}
	printf("%I64d\n",f[n][m]%Mod);
	
	return 0;
}