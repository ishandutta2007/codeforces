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
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second 

const int MaxN=510;

int n,m;
int v[MaxN],e[MaxN][MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>v[i];
	for (int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[a][b]=e[b][a]=c;
	}
	ld ans=0;
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
		{
			if (e[i][j]==0) continue;
			ans=max(ans,(ld)(v[i]+v[j])/(e[i][j]));
		}
	printf("%.10f\n",ans);
	return 0;
}