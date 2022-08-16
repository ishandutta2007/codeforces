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

const int MaxN=2000010;

int N,L,T;
int a[MaxN];

int main()
{
	cin>>N>>L>>T;
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&a[i]);
		a[i+N]=a[i]+L;
	}
	T*=2;
	ll c=T/L;
	T%=L;
	ld ans=0;
	for (int i=1,j=1;i<=N;++i)
	{
		while (a[i+N]-a[j]>T) ++j;
		ans+=c*(N-1)+i+N-j;
	}
	for (int i=N,j=N+N;i>=1;--i)
	{
		while (a[j]-a[i]>T) --j;
		ans+=c*(N-1)+j-i;
	}
	printf("%.20lf\n",ans/8);
	return 0;
}