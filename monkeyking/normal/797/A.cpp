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

using namespace std;
namespace factorization
{
	inline vector <int> getfactors(int x)
	{
		vector <int> vec;
		for(int i=1;i*i<=x;i++)
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
	inline vector <pair<int,int> > factorize(int x)
	{
		vector <pair<int,int> > vec;
		int nx=x;
		for(int i=2;i*i<=x;i++)
		{
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
				}
				vec.push_back(make_pair(i,s));
			}
		}
		if(nx!=1) vec.push_back(make_pair(nx,1));
		return vec;
	}
	inline vector <int> factorizeflat(int x)
	{
		vector <int> vec;
		int nx=x;
		for(int i=2;i*i<=x;i++)
		{
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
					vec.push_back(i);
				}
			}
		}
		if(nx!=1) vec.push_back(nx);
		return vec;
	}
};
using namespace factorization;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	vector <int> factors=factorizeflat(n);
	if(factors.size()<k) over(-1);
	int res=1;
	for(int i=0;i<k-1;i++)
	{
		cout<<factors[i]<<' ';
		res*=factors[i];
	}
	cout<<n/res<<endl;
	return 0;
}