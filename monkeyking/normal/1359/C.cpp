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
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;

long double calc(ll h,ll c,ll t,ll x)
{
	return abs((((long double)h*x+c*(x-1))/(2*x-1))-t);
}

ll solve(ll h,ll c,ll t0)
{
	long double t=(long double)(c-t0)/(h+c-2*t0);
	return (calc(h,c,t0,floor(t))<=calc(h,c,t0,ceil(t))?floor(t):ceil(t));
}

void solve()
{
	ll h,c,t;
	cin>>h>>c>>t;
	if(2*t<=h+c)
	{
		cout<<2<<endl;
		return;
	}
	cout<<2*solve(h,c,t)-1<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}