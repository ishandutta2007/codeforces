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
//ll C[30];
const ll mod=1e9+7;
const ll p=1e9+7;
ll n,k;
ll quick;

struct Form
{
	ll exp;
	ll eof;
};

ll ksm(ll basic,ll x)
{
	ll res=1;
	while(x)
	{
		if(x&1)
		{
			res*=basic;
			res%=mod;
		}
		basic*=basic;
		basic%=mod;
		x>>=1;
	}
	return res;
}

ll ny(ll x)
{
	return ksm(x,mod-2);
}

map <ll,ll> mul(map <ll,ll> a,map <ll,ll> b)
{
	map <ll,ll> res;
	for(auto x:a)
	{
		for(auto y:b)
		{
//			cout<<x.first<<' '<<y.first<<endl;
			res[x.first+y.first]+=(x.second*y.second)%mod;
			res[x.first+y.first]%=mod;
		}
	}
	return res;
}

inline ll Com(ll n,ll m)
{
	if(n<m) return 0;
	ll res=1;
	for(ll i=n;i>n-m;i--)
	{
		res*=(i%mod);
		res%=mod;
	}
	res*=quick;
	res%=mod;
//	for(ll i=1;i<=m;i++)
//	{
//		res*=ny((i%mod));
//		res%=mod;
//	}
	return res;
}

int main()
{
	cin>>n>>k;
//	C[0]=1;
//	for(int i=1;i<=25;i++)
//	{
//		C[i]=C[i-1];
//		C[i]*=(n+i-1);
//		C[i]%=mod;
//		C[i]*=ny(i-1);
//		C[i]%=mod;
//	}
//	cout<<n<<k<<endl;
	quick=1;
	for(ll i=1;i<=n-1;i++)
	{
		quick*=ny(i);
		quick%=mod;
	}
	map <ll,ll> res;
	res[0]=1;
	for(int i=0;i<n;i++)
	{
		map <ll,ll> t;
		ll x;
		cin>>x;
		t[0]=1;
		t[x+1]=-1;
		res=mul(res,t);
	}
	ll ans=0;
	for(auto x:res)
	{
		ans+=x.second*Com(n+k-x.first-1,n-1)%mod;
		ans%=mod;
	}
//	for(auto x:res)
//	{
//		cout<<'x'<<'^'<<x.first<<':'<<x.second<<endl;
//	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}