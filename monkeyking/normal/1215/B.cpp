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
int a[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	ll res=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	ll p0=1;
	ll p1=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum^=(a[i]<0);
		res+=(sum==0?p0:p1);
		if(sum==1) p1++;else p0++;
	}
	cout<<1LL*n*(n+1)/2-res<<' '<<res<<endl;
	return 0;
}