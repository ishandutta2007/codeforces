#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1<<17;

int n,MOD;
int a[MaxN],b[MaxN];
map<int,int> H,G;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		H[a[i]]++;
	}
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&b[i]);
		H[b[i]]++;
	}
	cin>>MOD;
	for (int i=1;i<=n;++i)
		if (a[i]==b[i]) G[a[i]]++;
	ll ans=1;
	for (map<int,int>::iterator it=H.begin();it!=H.end();++it)
	{
		int x=G[it->X];
		for (int i=2;i<=it->Y;++i)
		{
			if (x>0&&i%2==0)
			{
				(ans*=i/2)%=MOD;
				--x;
			}
			else
				(ans*=i)%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}