#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define X first
#define Y second

const int MaxN=100010;
const ll INF=1000000000000000000LL;

int n,m;
int a[MaxN];

bool check(ll x)
{
	ld s=0;
	for (int i=1;i<=n;++i) s+=x-a[i];
	return s>=x;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		m=max(m,a[i]);
	}
	ll L=m,R=INF,ans=INF;
	while (L<=R)
	{
		ll m=(L+R)/2;
		if (check(m))
		{
			ans=m;
			R=m-1;
		}
		else
			L=m+1;
	}
	cout<<ans<<endl;
	return 0;
}