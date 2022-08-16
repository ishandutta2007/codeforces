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

int n,m;
ld a[1000010],b[1000010];

ld C(int n,int m)
{
	if (n<m) return -1e100;
	return b[n]-b[m]-b[n-m];
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n*m;++i)
	{
		a[i]=log(i);
		b[i]=b[i-1]+a[i];
	}
	ld ans=0;
	for (int k=1;k<=n;++k)
	{
		ans=ans+exp(2*a[k]+C(m,k)+C((n-1)*m,n-k)-a[n]-C(n*m,n));
	}
	printf("%.9f\n",(double)ans);
	return 0;
}