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
using namespace std;
int n;
int a[100005];
ll sum[100005];

bool solve()
{
	map <ll,bool> m;
	bool res=false;
	for(int i=0;i<n;i++)
	{
		sum[i]=(i?sum[i-1]:0)+a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		ll l=sum[i];
		ll r=sum[n-1]-sum[i];
		m[a[i]]=true;
		l+=a[i+1];
		r-=a[i+1];
		ll delta=l-r;
		if(delta&1) continue;
		if(m[delta/2]) res=true;
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	bool res=false;
	res|=solve();
	for(int i=0;i<n;i++)
	{
		if(sum[i]==sum[n-1]-sum[i]) res=true;
	}
	reverse(a,a+n);
	res|=solve();
	cout<<(res?"YES":"NO")<<endl;
	return 0;
}