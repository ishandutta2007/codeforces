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

const int MOD=1000000007;
const int MaxN=100010;

ll pow2[MaxN],pow10[MaxN],num4[MaxN],num7[MaxN];
ll s[MaxN],p[MaxN];

ll delta(int i,ll k)
{
	return (p[i]+(2*s[i]-num4[i]-num7[i])%MOD*k+(pow2[i]-1)*k%MOD*k)%MOD;
}

void init()
{
	pow2[0]=pow10[0]=1;
	for (int i=1;i<=100000;++i)
	{
		pow2[i]=pow2[i-1]*2%MOD;
		pow10[i]=pow10[i-1]*10%MOD;
		num4[i]=(num4[i-1]*10+4)%MOD;
		num7[i]=(num7[i-1]*10+7)%MOD;
	}
	s[1]=11;
	p[1]=28;
	for (int i=2;i<=100000;++i)
	{
		s[i]=(s[i-1]*2+pow10[i-1]*pow2[i-1]%MOD*11)%MOD;
		p[i]=(delta(i-1,4*pow10[i-1]%MOD)+delta(i-1,7*pow10[i-1]%MOD)+(4*pow10[i-1]%MOD+num7[i-1])*(7*pow10[i-1]%MOD+num4[i-1]))%MOD;
	}
}

ll calc(string &a)
{
	int n=a.size();
	ll val=0;
	for (int i=0;i<n;++i)
		val=(val*10+a[i]-'0')%MOD;
	ll pre=0;
	ll ans=0;
	for (int i=0;i<n;++i)
	{
		pre=(pre+(a[i]-'0')*pow10[n-i-1])%MOD;
		if (a[i]=='7')
		{
			ll now=(pre-3*pow10[n-i-1])%MOD;
			ans=(ans+delta(n-i-1,now)+(now+num7[n-i-1])*(pre+num4[n-i-1]))%MOD;
		}
	}
	return ans;
}

void work()
{
	string a,b;
	cin>>a>>b;
	cout<<((calc(b)-calc(a))%MOD+MOD)%MOD<<endl;
}

int main()
{
	init();
	work();
	return 0;
}