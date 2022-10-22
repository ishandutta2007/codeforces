#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=3000+5,Mod=1000000007;
inline void simplemod(int &wei)
{
	(wei>=Mod)&&(wei-=Mod);
}
int a[MaxN][MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,m,k;
	while(T--)
	{
		cin>>n>>m>>k;
		rep(i,0,n)
		{
			rep(j,1,min(i,m))
			{
				if(j==i&&i<=m)
					simplemod(a[i][j]=a[i-1][j-1]+k);
				else
					a[i][j]=(long long)(a[i-1][j-1]+a[i-1][j])*((Mod+1)>>1)%Mod;
			}
		}
		cout<<a[n][m]<<'\n';
	}
	return 0;
}