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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1<<20;

int n,m;
int p[MaxN],q[MaxN];
int t,s[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	cin>>m;
	for (int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		q[x]=1;
	}
	for (int i=n;i>=1;--i)
	{
		if (!q[i]&&t&&p[s[t]]==p[i])
		{
			p[i]=-p[i];
			--t;
		}
		else
			s[++t]=i;
	}
	if (t)
		puts("NO");
	else
	{
		puts("YES");
		for (int i=1;i<=n;++i)
			printf("%d ",-p[i]);
	}
	return 0;
}