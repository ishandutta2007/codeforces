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
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=300010;

int n,m;
set<int> H;
int ans[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		H.insert(i);
	for (int i=1;i<=m;++i)
	{
		int a,b,x;
		scanf("%d%d%d",&a,&b,&x);
		vector<int> v;
		for (auto it=H.lower_bound(a);it!=H.end()&&*it<=b;++it)
		{
			if (*it!=x)
			{
				ans[*it]=x;
				v.push_back(*it);
			}
		}
		for (auto p : v)
			H.erase(p);
	}
	for (int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}