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

const int MaxN=1010;
const int MOD=1000000007;

int n,m;
int u[MaxN],p[MaxN];

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
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x;
		cin>>x;
		u[x]=1;
	}
	u[0]=u[n+1]=1;
	vector<int> v;
	int s=0;
	int t=0;
	for (int i=1;i<=n;++i)
	{
		if (u[i]) continue;
		if (!u[i-1]) continue;
		int j=i;
		while (j<=n&&!u[j+1]) ++j;
		v.push_back(j-i+1);
		s+=j-i+1;
		if (i>1&&j<n) t+=j-i;
	}
	p[0]=1;
	for (int i=1;i<=n;++i)
		p[i]=(ll)p[i-1]*i%MOD;
	int ans=p[s];
	for (int i=0;i<v.size();++i)
		ans=ans*power(p[v[i]],MOD-2)%MOD;
	cout<<ans*power(2,t)%MOD<<endl;
	return 0;
}