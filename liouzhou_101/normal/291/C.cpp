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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;

int n,k;
unsigned v[MaxN];

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
	{
		unsigned a,b,c,d;
		scanf("%u.%u.%u.%u",&a,&b,&c,&d);
		v[i]=a<<24|b<<16|c<<8|d;
	}
	for (int i=31;i>=0;--i)
	{
		unsigned s=0;
		for (int j=31;j>=i;--j)
			s|=1u<<j;
		vector<unsigned> p;
		for (int j=1;j<=n;++j)
			p.push_back(v[j]&s);
		sort(p.begin(),p.end());
		int m=1;
		for (int j=1;j<n;++j)
			if (p[j]!=p[j-1]) ++m;
		if (m==k)
		{
			printf("%u.%u.%u.%u\n",s>>24&255,s>>16&255,s>>8&255,s&255);
			return 0;
		}
	}
	puts("-1");
	return 0;
}