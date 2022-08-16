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

const int MaxN=500010;

int n;
int a[MaxN];

bool check(int m)
{
	for (int i=1,j=m+1;i<=m;++i)
	{
		while (j<=n)
		{
			if (a[j]>=2*a[i]) break;
			++j;
		}
		if (j>n) return false;
		++j;
	}
	return true;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int L=0,R=n,ans=0;
	while (L<=R)
	{
		int m=(L+R)/2;
		if (check(m))
		{
			ans=m;
			L=m+1;
		}
		else
			R=m-1;
	}
	cout<<n-ans<<endl;
	return 0;
}