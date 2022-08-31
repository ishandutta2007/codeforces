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

const int MaxN=200010;

ll n,k;
int a[MaxN];

int main()
{
	cin>>n>>k;
	ld sum=0,nn=n,mm=1;
	for (ll i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		ld t=sum-(ld)(nn-mm)*(mm-1)*a[i];
		if (t<k)
		{
			printf("%d\n",(int)i);
			--nn;
		}
		else
		{
			sum+=a[i]*(mm-1);
			++mm;
		}
	}
	return 0;
}