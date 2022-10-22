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
int a[1000005];
set <pair<int,int> > mn;
set <pair<int,int>,greater<pair<int,int> > >mx;
vector <pair<int,int> > tbd;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	ll premn=0;
	ll res=0;
	ll premx=0;
	for(int i=0;i<n;i++)
	{
		set <pair<int,int> > :: iterator it=mn.upper_bound(mp(a[i],0));
		int cnt=1;
		tbd.clear();
		for(;it!=mn.end();it++)
		{
			tbd.push_back(*it);
			cnt+=it->second;
			premn-=1LL*it->first*it->second;
		}
		for(int i=0;i<tbd.size();i++)
		{
			mn.erase(tbd[i]);
		}
		mn.insert(mp(a[i],cnt));
		premn+=1LL*a[i]*cnt;
		
		it=mx.upper_bound(mp(a[i],inf));
		cnt=1;
		tbd.clear();
		for(;it!=mx.end();it++)
		{
			tbd.push_back(*it);
			cnt+=it->second;
			premx-=1LL*it->first*it->second;
		}
		for(int i=0;i<tbd.size();i++)
		{
			mx.erase(tbd[i]);
		}
		mx.insert(mp(a[i],cnt));
		premx+=1LL*a[i]*cnt;
		res+=premx-premn;
	}
	cout<<res<<endl;
	return 0;
}