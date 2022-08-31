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
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=400010;

int n;
int a[MaxN],b[MaxN];
priority_queue<int> v[MaxN];

int p[MaxN],s[MaxN];

void add(int k,int L,int R,int x,int d)
{
	p[k]+=d;
	s[k]+=d*x;
	if (L==R)
		return;
	int m=(L+R)>>1;
	if (x<=m)
		add(k<<1,L,m,x,d);
	else
		add(k<<1|1,m+1,R,x,d);
}

int get(int k,int L,int R,int x)
{
	if (p[k]<x)
		return 1000000000;
	if (L==R)
		return x*L;
	int m=(L+R)>>1;
	if (p[k<<1]>=x)
		return get(k<<1,L,m,x);
	return s[k<<1]+get(k<<1|1,m+1,R,x-p[k<<1]);
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]==0||b[i]==0)
		{
			a[i]=b[i]=0;
			v[0].push(0);
		}
		else
		{
			v[a[i]].push(-b[i]);
			add(1,1,100000,b[i],1);
		}
	}
	priority_queue<pii> Q;
	for (int i=0;i<=100000;++i)
		Q.push(pii(v[i].size(),i));
	int sum=0;
	int rank=v[0].size();
	int ans=1000000000;
	for (int i=n;i>=1;--i)
	{
		while (Q.top().X>=i)
		{
			int x=Q.top().X;
			int k=Q.top().Y;
			Q.pop();
			Q.push(pii(x-1,k));
			sum-=v[k].top();
			add(1,1,100000,-v[k].top(),-1);
			v[k].pop();
			++rank;
		}
		int need=0;
		if (rank<i) need=get(1,1,100000,i-rank);
		ans=min(ans,sum+need);
	}
	cout<<ans<<endl;
	return 0;
}