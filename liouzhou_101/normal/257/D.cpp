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
typedef pair<ll,int> pli;

#define X first
#define Y second

const int MaxN=100010;

int n;
int a[MaxN],v[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=n-1,sum=a[n];i>=1;--i)
	{
		if (a[i]<=sum)
		{
			v[i]^=1;
			v[i+1]^=1;
			sum-=a[i];
		}
		else
		{
			v[i+1]^=1;
			sum=a[i]-sum;
		}
	}
	for (int i=1;i<=n;++i)
	{
		v[i]^=v[i-1];
		putchar(v[i]?'-':'+');
	}
	return 0;
}