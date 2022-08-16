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

const int MaxN=512;

int main()
{
	int n,m,k;
	int a[MaxN];
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	int sum=k,ans=0;
	if (sum>=m)
	{
		puts("0");
		return 0;
	}
	for (int i=n;i>=1;--i)
	{
		sum+=a[i]-1;
		++ans;
		if (sum>=m)
		{
			cout<<ans<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}