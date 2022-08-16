#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

int n,c,a[110];

int main()
{
	cin>>n>>c;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	int ans=0;
	for (int i=1;i<n;++i)
		ans=max(ans,a[i]-a[i+1]-c);
	cout<<ans<<endl;
	return 0;
}