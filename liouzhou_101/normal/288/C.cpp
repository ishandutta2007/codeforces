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

const int MaxN=1000010;

int n;
ll ans;
int p[MaxN];

int main()
{
	cin>>n;
	int x=n;
	while (1)
	{
		int y=0;
		for (int i=0;i<=20;++i)
		{
			if ((1<<i)>x) break;
			if (!(x&1<<i)) y|=1<<i;
		}
		for (int i=y;i<=x;++i)
			p[i]=x-i+y;
		x=y-1;
		if (x<0) break;
	}
	for (int i=0;i<=n;++i)
		ans+=i^p[i];
	cout<<ans<<endl;
	for (int i=0;i<=n;++i)
		printf("%d ",p[i]);
	return 0;
}