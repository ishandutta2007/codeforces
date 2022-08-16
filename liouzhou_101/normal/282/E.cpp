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

const int MaxN=100010;

int n;
ll a[MaxN],s[MaxN],t[MaxN];

struct node
{
	node *s[2];
	node ()
	{
		s[0]=s[1]=0;
	}
};

struct trie
{
	node *r;
	void init()
	{
		r=new node;
	}
	void add(ll x)
	{
		node *p=r;
		for (int i=59;i>=0;--i)
		{
			if ((1LL<<i)&x)
			{
				if (!p->s[1])
					p->s[1]=new node;
				p=p->s[1];
			}
			else
			{
				if (!p->s[0])
					p->s[0]=new node;
				p=p->s[0];
			}
		}
	}
	ll solve(ll x)
	{
		node *p=r;
		ll c=0;
		for (int i=59;i>=0;--i)
		{
			int u=((1LL<<i)&x)?1:0;
			if (p->s[u^1])
			{
				p=p->s[u^1];
				c|=1LL<<i;
			}
			else
				p=p->s[u];
		}
		return c;
	}
}T;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%I64d",&a[i]);
	for (int i=1;i<=n;++i)
		s[i]=s[i-1]^a[i];
	for (int i=n;i>=1;--i)
		t[i]=t[i+1]^a[i];
	T.init();
	T.add(0);
	ll ans=s[n];
	for (int i=n;i>=0;--i)
	{
		ans=max(ans,T.solve(s[i]));
		T.add(t[i]);
	}
	cout<<ans<<endl;
	return 0;
}