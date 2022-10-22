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
ll n,k;

template <typename T>
inline vector <T> getfactors(T x)
{
	vector <T> vec;
	for(T i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			vec.push_back(i);
			if(i!=x/i) vec.push_back(x/i);
		}
	}
	sort(vec.begin(),vec.end());
	return vec;
}

ll sum(ll x)
{
	if(x>=10000000) return llinf;
	return x*(x+1)/2;
}

ll mul(ll a,ll b)
{
	if(a>=10000000 && b>=10000000 || a>10000000000LL || b>10000000000LL) return llinf;
	return a*b;
}

void print(ll gcd)
{
	n/=gcd;
	for(ll i=1;i<k;i++)
	{
		cout<<i*gcd<<' ';
		n-=i;
	}
	cout<<n*gcd<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	vector <ll> factors=getfactors(n);
	reverse(all(factors));
	for(auto gcd:factors)
	{
		ll t=mul(gcd,sum(k));
		if(t>n) continue;
		print(gcd);
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}