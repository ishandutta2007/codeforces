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

const int MOD=1000000007;

int n;
string s,t;

ll calc(string s,string t)
{
	ll p=1;
	for (int i=0;i<n;++i)
	{
		if (s[i]=='?'&&t[i]=='?')
			p=p*55%MOD;
		else if (s[i]=='?')
			p=p*(t[i]-'0'+1)%MOD;
		else if (t[i]=='?')
			p=p*('9'-s[i]+1)%MOD;
		else if (s[i]>t[i])
			p=0;
	}
	return p;
}

ll equal(string s,string t)
{
	ll p=1;
	for (int i=0;i<n;++i)
		if (s[i]=='?'&&t[i]=='?')
			p=p*10%MOD;
		else if (s[i]=='?'||t[i]=='?')
			p=p;
		else if (s[i]!=t[i])
			p=0;
	return p;
}

int main()
{
	cin>>n>>s>>t;
	ll p=1;
	for (int i=0;i<n;++i)
	{
		if (s[i]=='?') p=p*10%MOD;
		if (t[i]=='?') p=p*10%MOD;
	}
	cout<<((p-calc(s,t)-calc(t,s)+equal(s,t))%MOD+MOD)%MOD<<endl;
	return 0;
}