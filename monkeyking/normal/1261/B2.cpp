#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int a[200005];
pair<int,int> s[200005];
int seq[200005];
int data[400005];
pair<pii,int> qr[200005];
int ans[200005];
int nn;

void add(int x,int delta)
{
	while(x<=nn)
	{
		data[x]+=delta;
		x+=x & (-x);
	}
}

int query(int x)
{
	int res=0;
	while(x)
	{
		res+=data[x];
		x&=(x-1);
	}
	return res;
}

bool compare(pii a,pii b)
{
	if(a.first!=b.first) return a.first>b.first;
	return a.second<b.second;
}

int solve(int k,int pos)
{
	int l=1,r=n,m,res=-1;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<query(i)<<' ';
//	}
//	cout<<endl;
	while(l<=r)
	{
		m=(l+r)>>1;
//		cout<<l<<' '<<r<<' '<<m<<endl;
		if(query(m)<pos)
		{
//			res=min(res,m);
			l=m+1;
		}
		else
		{
			res=m;
			r=m-1;
		}
	}
//	cout<<pos<<' '<<res<<endl;
	assert(res!=-1);
	return a[res-1];
//	for(int i=1;i<=n;i++)
//	{
//		if(query(i)==pos)
//		{
////			cout<<i<<' '<<a[i-1]<<endl;
//			return a[i-1];
//		}
//	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		s[i].first=a[i];
		s[i].second=i;
	}
	sort(s,s+n,compare);
	nn=1;
	while(nn<=n)
	{
		nn<<=1;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int k,pos;
		scanf("%d%d",&k,&pos);
		qr[i]=mp(mp(k,pos),i);
	}
	sort(qr,qr+q);
	int dealnum=0;
	for(int i=0;i<n;i++)
	{
		add(s[i].second+1,1);
		while(dealnum<q && qr[dealnum].first.first==i+1)
		{
			ans[qr[dealnum].second]=solve(i+1,qr[dealnum].first.second);
			dealnum++;
		}
	}
	for(int i=0;i<q;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}