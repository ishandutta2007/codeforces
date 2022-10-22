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
#define abs(a) (a>0?a:-a)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
vector <pll> vec;

int main()
{
//	freopen("input.txt","r",stdin);
	ll n,b;
	cin>>n>>b;
	ll tb=b;
	ll s=0;
	for(ll i=2;i*i<=tb;i++)
	{
		s=0;
		if(tb%i==0)
		{
			while(tb%i==0)
			{
				tb/=i;
				s++;
			}
			vec.push_back(mp(i,s));
		}
	}
	if(tb!=1) vec.push_back(mp(tb,1));
	ll res=1LL*inf*inf;
	for(int i=0;i<vec.size();i++)
	{
		ll x=vec[i].first;
		s=0;
		ll tn=n;
		while(tn)
		{
			tn/=x;
			s+=tn;
		}
		res=min(res,s/vec[i].second);
	}
	cout<<res<<endl;
	return 0;
}