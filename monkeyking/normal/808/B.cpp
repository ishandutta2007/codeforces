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
int a[200005];
int n,k;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		a[i]=k;
	}
	int st=0;
	for(int i=1;i<=n;i++)
	{
		if(i+k-1<=n) st++;
		a[i]=min(a[i],st);
	}
	st=0;
	for(int i=n;i>=1;i--)
	{
		if(i-k+1>=1) st++;
		a[i]=min(a[i],st);
	}
	ll x;
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		res+=x*a[i];
	}
	cout.precision(10);
	cout<<(long double)res/(n-k+1)<<endl;
	return 0;
}