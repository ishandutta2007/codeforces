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
int a[105];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i]==2 && a[i+1]==3 || a[i]==3 && a[i+1]==2)
		{
			over("Infinite");
		}
	}
	int res=0;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]==2 || a[i+1]==2)
		{
			res+=3;
		}
		else
		{
			res+=4;
		}
	}
	for(int i=0;i<n-2;i++)
	{
		if(a[i]==3 && a[i+1]==1 && a[i+2]==2) res--;
	}
	cout<<"Finite\n";
	cout<<res<<endl;
	return 0;
}