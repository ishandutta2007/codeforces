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

void solvemin(int a1,int a2,int k1,int k2,int n)
{
	n-=(k1-1)*a1;
	n-=(k2-1)*a2;
	if(n<0)
	{
		cout<<0<<' ';
		return;
	}
	cout<<n<<' ';
}

void solvemax(int a1,int a2,int k1,int k2,int n)
{
	if(k1>k2)
	{
		if(n>=a2*k2)
		{
			n-=a2*k2;
			cout<<a2+n/k1<<endl;
		}
		else
		{
			cout<<n/k2<<endl;
		}
	}
	else
	{
		if(n>=a1*k1)
		{
			n-=a1*k1;
			cout<<a1+n/k2<<endl;
		}
		else
		{
			cout<<n/k1<<endl;
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int a1,a2,k1,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;
	solvemin(a1,a2,k1,k2,n);
	solvemax(a1,a2,k1,k2,n);
	return 0;
}