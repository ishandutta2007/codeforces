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

int n;
pii a[MaxN];
int b[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i].X);
		a[i].Y=i;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	int last=0;
	for (int i=1;i<=n;++i)
	{
		if (a[i].X<=last)
			a[i].X=last+1;
		last=b[a[i].Y]=a[i].X;
		ans+=a[i].X;
	}
	//cout<<ans<<endl;
	for (int i=1;i<=n;++i)
		printf("%d ",b[i]);
	return 0;
}