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

const int MaxN=110;

int n,m;
int F[MaxN];

int father(int x)
{
	return (F[x]==x)?x:F[x]=father(F[x]);
}

vector<int> v[MaxN],w[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		F[i]=i;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		F[father(x)]=father(y);
	}
	for (int i=1;i<=n;++i)
		v[father(i)].push_back(i);
	for (int i=1;i<=n;++i)
	{
		if (v[i].size()>3)
		{
			puts("-1");
			return 0;
		}
		w[v[i].size()].push_back(i);
	}
	if (w[3].size()+w[2].size()>n/3)
	{
		puts("-1");
		return 0;
	}
	for (int i=0;i<w[3].size();++i)
	{
		int x=w[3][i];
		for (int j=0;j<3;++j)
			cout<<v[x][j]<<" ";
		cout<<endl;
	}
	for (int i=0;i<w[2].size();++i)
	{
		int x=w[2][i];
		cout<<v[x][0]<<" "<<v[x][1]<<" "<<v[w[1][i]][0]<<endl;
	}
	for (int i=w[2].size();i<w[1].size();i+=3)
	{
		cout<<v[w[1][i]][0]<<" "<<v[w[1][i+1]][0]<<" "<<v[w[1][i+2]][0]<<endl;
	}
	return 0;
}