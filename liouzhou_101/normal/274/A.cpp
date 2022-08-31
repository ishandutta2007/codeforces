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

int n,k;
set<ll> H;

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		H.insert(x);
	}
	int ans=0;
	while (!H.empty())
	{
		int tot=1;
		ll x=*H.begin();
		H.erase(x);
		while (1)
		{
			x*=k;
			if (!H.count(x)) break;
			++tot;
			H.erase(x);
		}
		ans+=(tot+1)/2;
	}
	cout<<ans<<endl;
	return 0;
}