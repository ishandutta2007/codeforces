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
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;

int n,m;
int a[MaxN],b[MaxN];
ull sa[MaxN],sb[MaxN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for (int i=1;i<=n;++i)
		sa[i]=sa[i-1]+a[i];
	for (int i=1;i<=m;++i)
		sb[i]=sb[i-1]+b[i];
	ull ansa=sb[m];
	ull ansb=sa[n];
	for (int i=1;i<m;++i)
		ansb+=min((ull)b[i],sa[n]);
	for (int i=1;i<n;++i)
		ansa+=min((ull)a[i],sb[m]);
	cout<<min(ansa,ansb)<<endl;
	return 0;
}