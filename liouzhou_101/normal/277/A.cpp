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

const int MaxN=120;

int n,m;
bitset<MaxN> a[MaxN];
int u[MaxN],v[MaxN][MaxN];
int ans;

void DFS(int x)
{
	u[x]=1;
	for (int i=1;i<=n;++i)
		if (v[x][i]&&!u[i])
			DFS(i);
}

int main()
{
	cin>>n>>m;
	int t=0;
	for (int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		if (k) t=1;
		for (int j=1;j<=k;++j)
		{
			int x;
			cin>>x;
			a[i][x]=1;
		}
	}
	if (!t)
	{
		cout<<n<<endl;
		return 0;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			if ((a[i]&a[j]).count()) v[i][j]=1;
	for (int i=1;i<=n;++i)
		if (!u[i])
		{
			++ans;
			DFS(i);
		}
	cout<<ans-1<<endl;
	return 0;
}