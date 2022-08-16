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
const int MOD=1000000007;

ll a,b,n,ans;
ll p[MaxN],r[MaxN];

ll power(ll x,ll y)
{
	if (!y) return 1;
	ll t=power(x,y/2);
	t=t*t%MOD;
	if (y%2) t=t*x%MOD;
	return t;
}

int main()
{
	cin>>a>>b>>n;
	p[0]=1;
	r[0]=1;
	for (int i=1;i<=n;++i)
	{
		p[i]=p[i-1]*i%MOD;
		r[i]=power(p[i],MOD-2);
	}
	for (int k=1;k<=7;++k)
	for (int s=0;s<1<<k;++s)
	{
		int t=0;
		for (int j=0;j<k;++j)
		{
			t=t*10;
			t+=(s&1<<j)?b:a;
		}
		/*
		a*x+b*(n-x)=t
		a*x+b*n-b*x=t
		(a-b)*x=t-b*n
		(b-a)*x=b*n-t
		*/
		if (b*n-t>=0&&(b*n-t)%(b-a)==0)
		{
			ll x=(b*n-t)/(b-a);
			if (x<=n)
				ans+=p[n]*r[x]%MOD*r[n-x]%MOD;
		}
	}
	cout<<ans%MOD<<endl;
	return 0;
}