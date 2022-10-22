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
char a[1005],b[1005];
int res=inf;
int n,m;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	scanf("%s",a);
	scanf("%s",b);
	int k=-1;
	for(int i=0;i<m-n+1;i++)
	{
		int now=0;
		for(int pos=0;pos<n;pos++)
		{
			now+=(a[pos]!=b[pos+i]);
		}
		if(now<res)
		{
			res=now;
			k=i;
		}
	}
	cout<<res<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[k+i])
		{
			cout<<i+1<<' ';
		}
	}
	cout<<endl;
	return 0;
}