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

const int MaxN=80010;

int n;
vector<int> v[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

int s[MaxN],p[MaxN],d[MaxN],a[MaxN];

void DFS(int x,int p)
{
	::p[x]=p;
	s[x]=1;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=p)
		{
			d[*it]=d[x]+1;
			DFS(*it,x);
			s[x]+=s[*it];
		}
}

bool cmp_d(int i,int j)
{
	return d[i]<d[j];
}

ll F[MaxN];
ll ans;

void work()
{
	DFS(1,0);
	for (int i=2;i<=n;++i)
	{
		F[p[i]]+=(ll)(s[p[i]]-s[i])*s[i]*(s[i]-1)/2;
	}
	for (int i=1;i<=n;++i)
		a[i]=i;
	sort(a+1,a+n+1,cmp_d);
	for (int k=n;k>=1;--k)
	{
		int i=a[k];
		ll tmp=(ll)(s[i]-1)*(s[i]-2)/2;
		for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it) if (*it!=p[i])
			tmp-=(ll)s[*it]*(s[*it]-1)/2;
		
		for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it) if (*it!=p[i])
		{
			ans+=F[*it]*(s[i]-s[*it]);
			ans+=(ll)((s[i]-s[*it]-1)+tmp-(ll)s[*it]*(s[i]-s[*it]-1))*s[*it]*(s[*it]-1)/2;
		}
		ans+=(ll)(tmp+s[i]-1)*(n-s[i])*(n-s[i]-1)/2;
		F[p[i]]+=F[i];
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}