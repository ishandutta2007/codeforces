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
int n;
ll a[100005];

void fi()
{
	cout<<"sjfnb\n";
	exit(0);
}

void se()
{
	cout<<"cslnb\n";
	exit(0);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",a+i);
	}
	if(n==1)
	{
		if(a[0]&1)
		{
			fi();
		}
		else
		{
			se();
		}
	}
	sort(a,a+n);
	int equals=0;
	for(int i=0;i<n-1;i++)
	{
		equals+=(a[i]==a[i+1]);
	}
	if(equals>=2) se();
	for(int i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1] && (a[i]==0 || (i && a[i]-1==a[i-1]))) se();
	}
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	if((sum-1LL*n*(n-1)/2)&1) fi();else se();
	return 0;
}