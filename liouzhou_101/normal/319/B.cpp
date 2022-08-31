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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;

int n,a[MaxN];
int t,q[MaxN];
int ans,f[MaxN];

int main()
{
	cin>>n;
	for (int i=n;i>=1;--i)
		cin>>a[i];
	for (int i=1;i<=n;++i)
	{
		while (t)
		{
			if (a[q[t]]>a[i]) break;
			f[i]=max(f[i]+1,f[q[t]]);
			--t;
		}
		ans=max(ans,f[i]);
		q[++t]=i;
	}
	cout<<ans<<endl;
	return 0;
}