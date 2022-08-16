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

const int MaxN=1000010;

int n,m;
vector<int> v[MaxN];
int F[MaxN];

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
	{
		int x=0;
		sort(v[i].begin(),v[i].end());
		v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
		for (int j=0;j<v[i].size();++j)
			if (F[v[i][j]]) ++x;
		if (x>1)
			F[i]=0;
		else
			F[i]=1;
	}
	for (int i=1;i<=n;++i)
	{
		int x=0;
		for (int j=0;j<v[i].size();++j)
			if (F[i]==F[v[i][j]]) ++x;
		if (x>1)
		{
				for (int i=1;i<=n;++i)
	{
		int x=0;
		sort(v[i].begin(),v[i].end());
		v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
		for (int j=0;j<v[i].size();++j)
			if (F[v[i][j]]) ++x;
		if (x<=1)
			F[i]=0;
		else
			F[i]=1;
	}
			break;
		}
	}
	for (int i=1;i<=n;++i)
		printf("%d",F[i]);
	return 0;
}