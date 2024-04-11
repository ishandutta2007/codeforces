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
double a[100005];

int up(double x)
{
	if((int)x>x) return (int)x;else return (int)x+1;
}

int down(double x)
{
	if((int)x<x) return (int)x;else return (int)x-1;
}

int main()
{
	ios_base::sync_with_stdio(false);
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==(int)a[i]) k++;
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==(int)a[i])
		{
			sum+=a[i];
			continue;
		}
		sum+=down(a[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==(int)a[i]) cout<<(int)a[i]<<endl;
		else
		{
			if(sum<0)
			{
				cout<<up(a[i])<<endl;
				sum++;
			}
			else
			{
				cout<<down(a[i])<<endl;
			}
		}
	}
	return 0;
}