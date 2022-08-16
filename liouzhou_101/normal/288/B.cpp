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

int n,k;
int v[]={0,1,2,9,64,625,7776,117649,2097152};

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
	cin>>n>>k;
	cout<<v[k]*power(n-k,n-k)%MOD<<endl;
	return 0;
}