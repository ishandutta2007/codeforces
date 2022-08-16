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

const int MaxN=300010;

int n,m;
vector<int> v[MaxN];
int F[MaxN];
queue<int> Q;

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;++i)
		Q.push(i);
	while (!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		int t=0;
		for (int i=0;i<v[x].size();++i)
			if (F[x]==F[v[x][i]]) ++t;
		if (t>=2)
		{
			F[x]^=1;
			for (int i=0;i<v[x].size();++i)
				Q.push(v[x][i]);
		}
	}
	for (int i=1;i<=n;++i)
		printf("%d",F[i]);
	return 0;
}