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
int a[300005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	int res=0;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]!=a[0])
		{
			res=max(res,i);
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[n-1])
		{
			res=max(res,n-i-1);
			break;
		}
	}
	cout<<res<<endl;
	return 0;
}