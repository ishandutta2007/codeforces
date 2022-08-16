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

typedef long long int64;
typedef long double real;
typedef pair<int,int> pii;

#define X first
#define Y second

const int MaxN=100010;

int n;
int c[MaxN],s[MaxN];
set<pii> v[2];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&c[i],&s[i]);
		v[c[i]].insert(make_pair(s[i],i));
	}
	for (int i=1;i<n;++i)
	{
		int w=1;
		if (pii(v[0].begin()->X,-(int)v[0].size())<pii(v[1].begin()->X,-(int)v[1].size())) w=0;
		printf("%d %d %d\n",v[w].begin()->Y,v[w^1].begin()->Y,v[w].begin()->X);
		const_cast<int&>(v[w^1].begin()->X)-=v[w].begin()->X;
		v[w].erase(v[w].begin());
	}
	return 0;
}