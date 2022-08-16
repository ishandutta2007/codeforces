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

const int MaxN=100010;

int n;
vector<int> v[MaxN];
pll F[MaxN];
int w[MaxN];

void solve(int x,int p)
{
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (p!=*it)
		{
			solve(*it,x);
			F[x].X=max(F[x].X,F[*it].X);
			F[x].Y=max(F[x].Y,F[*it].Y);
		}
	ll t=w[x]-F[x].X+F[x].Y;
	if (t>0)
		F[x].X+=t;
	else
		F[x].Y-=t;
}

int main()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;++i)
		scanf("%d",&w[i]);
	solve(1,0);
	cout<<F[1].X+F[1].Y<<endl;
	return 0;
}