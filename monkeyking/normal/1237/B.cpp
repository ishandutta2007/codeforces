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
int a[100005];
int b[100005];
int name[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",b+i);
		b[i]--;
	}
	for(int i=0;i<n;i++)
	{
		name[a[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		b[i]=name[b[i]];
	}
	int minid=n+1;
	int res=0;
	for(int i=n-1;i>=0;i--)
	{
		if(b[i]>minid) res++;
		minid=min(minid,b[i]);
	}
	cout<<res<<endl;
	return 0;
}