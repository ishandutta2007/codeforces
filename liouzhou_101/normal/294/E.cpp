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

const int MaxN=5010;
const ll INF=1000000000000000000LL;

int n;
vector<pii> v[MaxN],w[MaxN];
int s[MaxN],p[MaxN];

void build(int x,int p)
{
	s[x]=1;
	::p[x]=p;
	for (vector<pii>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (it->X!=p)
		{
			w[x].push_back(*it);
			build(it->X,x);
			s[x]+=s[it->X];
		}
}

void init()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		v[x].push_back(pii(y,w));
		v[y].push_back(pii(x,w));
	}
	build(1,0);
}

pii limit;
ll d[MaxN];
ll val,get,sum;

void solve(int x,int num)
{
	for (vector<pii>::iterator it=w[x].begin();it!=w[x].end();++it)
	{
		if (pii(x,it->X)==limit) continue;
		val+=(ll)it->Y*s[it->X];
		d[it->X]=d[x]+(ll)it->Y*(num-2*s[it->X]);
		get=min(get,d[it->X]);
		sum+=(ll)it->Y*s[it->X]*(num-s[it->X]);
		solve(it->X,num);
	}
}

void work()
{
	ll ans=INF;
	for (int i=1;i<=n;++i)
		for (vector<pii>::iterator it=w[i].begin();it!=w[i].end();++it)
		{
			limit=pii(i,it->X);
			for (int x=i;x;x=p[x])
				s[x]-=s[it->X];
			d[1]=d[it->X]=0;
			
			sum=(ll)it->Y*s[it->X]*(n-s[it->X]);
			val=0;
			get=0;
			solve(1,s[1]);
			sum+=(val+get)*s[it->X];
			
			val=0;
			get=0;
			solve(it->X,s[it->X]);
			sum+=(val+get)*s[1];
			
			ans=min(ans,sum);
			
			for (int x=i;x;x=p[x])
				s[x]+=s[it->X];
		}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}