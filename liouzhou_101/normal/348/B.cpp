#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;

#define X first
#define Y second

const int MaxN=100010;
const ll INF=100000000000001LL;

int n;
ll a[MaxN],sum,u[MaxN];
vector<int> v[MaxN];
ll need[MaxN];

ll gcd(ll x,ll y)
{
	return (!y)?x:gcd(y,x%y);
}

void DFS(int x,int p)
{
	if (need[x]>INF) need[x]=INF;
	int flag=0;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
	{
		if (*it==p) continue;
		need[*it]=need[x]*(ll)(v[x].size()-(x!=1));
		DFS(*it,x);
		flag=1;
	}
	u[x]=1-flag;
}

bool check(ll m)
{
	for (int i=1;i<=n;++i)
		if (u[i])
			if (m/need[i]>a[i]) return false;
	return true;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		a[i]=x;
		if (x) u[i]=1;
		sum+=x;
	}
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	need[1]=1;
	DFS(1,0);
	ll limit=1;
	for (int i=1;i<=n;++i)
	{
		ll c=gcd(limit,need[i]);
		if (limit/c*(ld)need[i]>=INF)
		{
			limit=INF;
			break;
		}
		limit=limit/c*need[i];
	}
	if (limit>=INF)
	{
		cout<<sum<<endl;
		return 0;
	}
	ll L=0,R=sum/limit+1,ans=0;
	while (L<=R)
	{
		ll m=(L+R)/2;
		if (check(m*limit))
		{
			ans=m*limit;
			L=m+1;
		}
		else
			R=m-1;
	}
	cout<<sum-ans<<endl;
	return 0;
}