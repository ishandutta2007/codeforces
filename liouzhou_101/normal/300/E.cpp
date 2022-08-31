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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n;
int p[10000010],d[10000010];
int s[10000010];

int k;
ll u[10000010];

bool check(ll x)
{
	for (int i=1;i<=n;++i)
	{
		ll t=x,v=0;
		while (t)
		{
			v+=t/p[i];
			t/=p[i];
		}
		if (v<u[i]) return 0;
	}
	return 1;
}

//vector<int> v[26];

int main()
{
	for (int i=2;i<=10000000;++i)
	{
		if (!d[i])
		{
			p[++n]=i;
			d[i]=n;
		}
		for (int j=1;i*p[j]<=10000000;++j)
		{
			d[i*p[j]]=j;
			if (i%p[j]==0) break;
		}
	}
	/*
	for (int i=1;i<=23;++i)
		for (int j=1;;++j)
		{
			ll t=1;
			for (int k=1;k<=i;++k)
				t*=j;
			if (t>10000000) break;
			v[i].push_back(t);
		}
	*/
	cin>>k;
	for (int i=1;i<=k;++i)
	{
		int a;
		scanf("%d",&a);
		/*
		for (int j=1;j<=23;++j)
		{
			int y=upper_bound(v[j].begin(),v[j].end(),a)-v[j].begin();
			s[y]+=1;
		}
		*/
		s[a]+=1;
		/*
		for (int j=1;j<=a;++j)
		{
			int x=j;
			while (d[x])
			{
				u[d[x]]+=1;
				x/=p[d[x]];
			}
		}
		*/
	}
	
	for (int i=10000000;i>=1;--i)
		s[i]+=s[i+1];
	for (int i=2;i<=10000000;++i)
	{
		//if (p[d[i]]!=i) continue;
		int x=i;
		while (d[x])
		{
			u[d[x]]+=s[i];
			x/=p[d[x]];
		}
	}
	/*
	for (int i=1;i<=10;++i)
		printf("%d\n",u[i]);
	*/
	ll L=1,R=10000000000000000LL;
	ll ans=R;
	while (L<=R)
	{
		ll m=(L+R)/2;
		if (check(m))
		{
			ans=m;
			R=m-1;
		}
		else
			L=m+1;
	}
	cout<<ans<<endl;
	return 0;
}