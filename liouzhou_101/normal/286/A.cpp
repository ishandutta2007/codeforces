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

const int MaxN=1<<17;

int n;
int p[MaxN];

int main()
{
	cin>>n;
	if (n%4==2||n%4==3)
	{
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n/4;++i)
	{
		p[i*2-1]=i*2;
		p[i*2]=n-i*2+2;
		p[n-i*2+2]=n-i*2+1;
		p[n-i*2+1]=i*2-1;
	}
	if (n%4==1)
		p[n/2+1]=n/2+1;
	for (int i=1;i<=n;++i)
		printf("%d ",p[i]);
	return 0;
}