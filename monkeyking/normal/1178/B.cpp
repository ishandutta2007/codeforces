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
int l[1000005];
int r[1000005];
int n;

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	n=strlen(c);
	l[1]=(c[0]=='v' && c[1]=='v');
	for(int i=2;i<n;i++)
	{
		l[i]=l[i-1]+(c[i-1]=='v' && c[i]=='v');
	}
	r[n-2]=(c[n-1]=='v' && c[n-2]=='v');
	for(int i=n-3;i>=0;i--)
	{
		r[i]=r[i+1]+(c[i]=='v' && c[i+1]=='v');
	}
	ll res=0;
	for(int i=0;i<n;i++)
	{
		if(c[i]!='o') continue;
		res+=1LL*l[i]*r[i];
	}
	cout<<res<<endl;
	return 0;
}