#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;
const int INF=1000000010;

int n,m,k;
int a[MaxN],b[MaxN];
int ta=INF,tb=INF;

int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		ta=min(ta,a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&b[i]);
		tb=min(tb,b[i]);
	}
	sort(b+1,b+m+1);
	int j=0;
	for (int i=1;i<=n;++i)
	{
		++j;
		while (j<=m&&b[j]<a[i]) ++j;
		if (j>m)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}