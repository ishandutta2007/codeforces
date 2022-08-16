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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1010;

int n,x;
int a[MaxN];
vector<int> v[MaxN];
vector<int> p;
int F[MaxN],r[MaxN];

int main()
{
	cin>>n>>x;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		if (a[i]) v[a[i]].push_back(i);
	}
	for (int i=1;i<=n;++i)
		if (!a[i])
		{
			int x=i,k=1,f=0;
			while (1)
			{
				if (x==::x) f=1;
				r[x]=k;
				if (v[x].empty()) break;
				++k;
				x=v[x][0];
			}
			if (!f) p.push_back(k);
		}
	F[0]=1;
	for (int j=1;j<=p.size();++j)
		for (int i=n;i>=0;--i)
			if (F[i])
			{
				if (i+p[j-1]<=n) F[i+p[j-1]]=1;
			}
	for (int i=0;i<=n;++i)
		if (F[i]) printf("%d\n",i+r[x]);
	return 0;
}