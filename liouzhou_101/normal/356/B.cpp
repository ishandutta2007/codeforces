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

const int MaxN=1000010;

ll n,m,ls,lt;
char s[MaxN],t[MaxN];
int F[MaxN][26];

ll gcd(ll a,ll b)
{
	return (!b)?a:gcd(b,a%b);
}

int main()
{
	cin>>n>>m;
	scanf("%s%s",s,t);
	ls=strlen(s);
	lt=strlen(t);
	ll d=gcd(ls,lt);
	for (int i=0;i<ls;++i)
		F[i%d][s[i]-'a']++;
	ll ans=0;
	for (int i=0;i<lt;++i)
	{
		ans+=F[i%d][t[i]-'a'];
	}
	ans*=n/(lt/d);
	ans=n*ls-ans;
	cout<<ans<<endl;
	return 0;
}