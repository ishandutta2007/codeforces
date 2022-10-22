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
int n,m,k;
ll ta,tb;
ll a[200005];
ll b[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>ta>>tb>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",a+i);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%I64d",b+i);
	}
	if(k>=n || k>=m) over("-1");
	ll res=-1;
	ll toB;
	ll last=0;
	for(int i=0;i<=k;i++)
	{
		toB=a[i]+ta;
		for(;last<m;last++)
		{
			if(last+(k-i)>=m) over("-1");
			if(toB<=b[last])
			{
				res=max(res,b[last+(k-i)]+tb);
				break;
			}
		}
	}
	if(last==m) over("-1");
	cout<<res<<endl;
	return 0;
}