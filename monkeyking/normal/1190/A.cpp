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
ll t;
ll n,k;
ll a[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>t>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",a+i);
		a[i]--;
	}
	ll dis=0;
	ll res=0;
	while(dis!=n)
	{
		ll page=(a[dis]-dis)/k;
		ll i;
		for(i=dis;i<n;i++)
		{
			if((a[i]-dis)/k!=page) break;
		}
		dis=i;
		res++;
	}
	cout<<res<<endl;
	return 0;
}