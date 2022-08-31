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

const int MaxN=100010;

int n;
vector<int> v[MaxN];
int d[MaxN];
ld ans;

void DFS(int x,int p)
{
	d[x]=d[p]+1;
	ans+=(ld)1/d[x];
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=p) DFS(*it,x);
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
	DFS(1,0);
	printf("%.20lf\n",(double)ans);
	return 0;
}