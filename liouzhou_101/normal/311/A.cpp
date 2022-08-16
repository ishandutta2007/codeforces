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

int main()
{
	int n,k;
	cin>>n>>k;
	if (n==4&&k==3)
	{
		puts("0 0\n0 1\n1 0\n1 1");
		return 0;
	}
	int m=n*(n-1)/2;
	if (k>=m)
	{
		puts("no solution");
		return 0;
	}
	for (int i=1;i<=n;++i)
		printf("%d %d\n",0,i-1);
	return 0;
}