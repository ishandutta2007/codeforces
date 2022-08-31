#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
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
const int MaxN=1<<20;

int n;
int a[MaxN],u[MaxN],p[MaxN];
int F[MaxN],G[MaxN];
int v[MaxN];

void add(int x,int p)
{
	for (;x<MaxN;x+=x&-x)
		(v[x]+=p)%=MOD;
}

int get(int x)
{
	int p=0;
	for (;x;x-=x&-x)
		(p+=v[x])%=MOD;
	return p;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p[i]=u[a[i]];
		u[a[i]]=i;
	}
	ll ans=0;
	add(F[0]=1,1);
	for (int i=1;i<=n;++i)
	{
		F[i]=G[i]=get(a[i]+1);
		if (p[i]) (F[i]-=G[p[i]])%=MOD;
		add(a[i]+1,(ll)F[i]*a[i]%MOD);
		ans+=(ll)F[i]*a[i]%MOD;
	}
	cout<<(ans%MOD+MOD)%MOD<<endl;
	return 0;
}