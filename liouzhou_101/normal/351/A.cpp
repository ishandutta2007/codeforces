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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=4010;

int ans,sum,n,x;

int main()
{
	cin>>n;
	for (int i=1;i<=2*n;++i)
	{
		ld x;
		cin>>x;
		int v=(int)(x*1000+.1);
		v-=v/1000*1000;
		sum+=v;
		if (!v) ++::x;
	}
	ans=1000000000;
	for (int i=0;i<=n;++i)
		if (n-i<=x) ans=min(ans,abs(sum-i*1000));
	printf("%d.%03d\n",ans/1000,ans%1000);
	return 0;
}