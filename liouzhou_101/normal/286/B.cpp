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

const int MaxN=1<<21;

int n;
int p[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		p[i]=i;
	int t=0;
	for (int i=2;i<=n;++i)
	{
		++t;
		p[t+n]=p[t+n-n%i];
		for (int j=n/i;j>=1;--j)
			p[t+i*j]=p[t+i*(j-1)];
	}
	for (int i=1;i<=n;++i)
		printf("%d ",p[t+i]);
	return 0;
}