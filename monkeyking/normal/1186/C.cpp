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
char c[1000005];
char b[1000005];
int n,k;
int sum[1000005];

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	scanf("%s",b);
	n=strlen(c);
	k=strlen(b);
	int t=0;
	for(int i=0;i<k;i++)
	{
		t+=(b[i]=='1');
	}
	sum[0]=(c[0]=='1');
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+(c[i]=='1');
	}
	int res=((sum[k-1]-t)%2==0);
	for(int i=k;i<n;i++)
	{
		res+=((sum[i]-sum[i-k]-t)%2==0);
	}
	cout<<res<<endl;
	return 0;
}