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
const int INF=1000000000;

int n;
pii s[MaxN];
int a[MaxN],b[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&s[i].X);
		s[i].Y=i;
	}
	sort(s+1,s+n+1);
	int m=(n-1)/3+1;
	for (int i=1;i<=n;++i)
	{
		if (i<=m)
		{
			a[s[i].Y]=0;
			b[s[i].Y]=s[i].X;
		}
		else if (i<=m*2)
		{
			a[s[i].Y]=s[i].X;
			b[s[i].Y]=0;
		}
		else
		{
			a[s[i].Y]=n-i;
			b[s[i].Y]=s[i].X-a[s[i].Y];
		}
	}
	puts("YES");
	for (int i=1;i<=n;++i)
		printf("%d ",a[i]);
	puts("");
	for (int i=1;i<=n;++i)
		printf("%d ",b[i]);
	puts("");
	return 0;
}