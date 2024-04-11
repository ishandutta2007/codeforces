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
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
int n;
ll bit[800005];
int nn;
int l[100005];
int r[100005];
pair<int,ll> a[400005];

void add(int x,ll delta)
{
	while(x<=nn)
	{
		bit[x]+=delta;
		x+=x&(-x);
	}
}

ll query(int x)
{
	ll res=0;
	while(x)
	{
		res+=bit[x];
		x&=(x-1);
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	nn=1;
	vector <int> lsh;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",l+i,r+i);
		lsh.push_back(l[i]);
		lsh.push_back(r[i]);
	}
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	vector <pair<int,int> > v;
	for(int i=0;i<lsh.size();i++)
	{
		if(i && lsh[i]-lsh[i-1]>=2) v.push_back(mp(lsh[i-1]+1,lsh[i]-1));
		v.push_back(mp(lsh[i],lsh[i]));
	}
	int k=0;
	for(auto tmp:v)
	{
		a[k]=mp(k+1,tmp.second-tmp.first+1);
		k++;
	}
	nn=1;
	while(nn<k) nn<<=1;
	for(int i=0;i<n;i++)
	{
		int id1=lower_bound(all(v),mp(l[i],l[i]))-v.begin();
		int id2=lower_bound(all(v),mp(r[i],r[i]))-v.begin();
		swap(a[id1],a[id2]);
	}
	ll res=0;
	ll total=0;
	for(int i=0;i<k;i++)
	{
		res+=(total-query(a[i].first))*a[i].second;
		total+=a[i].second;
		add(a[i].first,a[i].second);
	}
	cout<<res<<endl;
	return 0;
}