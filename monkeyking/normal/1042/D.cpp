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
ll t;
ll a[200005];
int bit[800005];
int nn;

void add(int x)
{
	while(x<=nn)
	{
		bit[x]++;
		x+=x&(-x);
	}
}

int query(int x)
{
	int res=0;
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
	ios_base::sync_with_stdio(false);
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector <ll> vSort;
	ll sum=0;
	ll res=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		vSort.push_back(sum-t);
		vSort.push_back(sum);
	}
	vSort.push_back(-llinf);
	vSort.push_back(0);
	sort(all(vSort));
	vSort.erase(unique(all(vSort)),vSort.end());
	sum=0;
	nn=1;
	while(nn<vSort.size()) nn<<=1;
	add(lower_bound(all(vSort),0)-vSort.begin());
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		int id=lower_bound(all(vSort),sum-t)-vSort.begin();
		res+=query(id);
		id=lower_bound(all(vSort),sum)-vSort.begin();
		add(id);
	}
	cout<<1LL*n*(n+1)/2-res<<endl;
	return 0;
}