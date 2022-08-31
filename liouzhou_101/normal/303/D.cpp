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

ll power(ll x,ll y,ll p)
{
	if (!y) return 1;
	ll t=power(x,y/2,p);
	t=t*t%p;
	if (y&1) t=t*x%p;
	return t;
}

bool isPrime(int n)
{
	for (int i=2;i*i<=n;++i)
		if (n%i==0) return false;
	return true;
}

bool isRoot(int n,int p)
{
	for (int i=2;i*i<p;++i)
		if ((p-1)%i==0)
			if (power(n,i,p)==1||power(n,(p-1)/i,p)==1)
				return false;
	return true;
}

int main()
{
	int n,x;
	cin>>n>>x;
	if (!isPrime(n+1))
	{
		puts("-1");
		return 0;
	}
	for (int i=x-1;i>=2;--i)
		if (isRoot(i,n+1))
		{
			cout<<i<<endl;
			return 0;
		}
	puts("-1");
	return 0;
}