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
bool a[10];

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	char x=0;
	cin>>n;
	for(int k=0;k<n;k++)
	{
		cin>>x;
		if(isdigit(x))
		{
			a[x-'0']=false;
			continue;
		}
		if(x=='L')
		{
			for(int i=0;i<10;i++)
			{
				if(a[i]==0)
				{
					a[i]=1;
					break;
				}
			}
		}
		if(x=='R')
		{
			for(int i=9;i>=0;i--)
			{
				if(a[i]==0) 
				{
					a[i]=1;
					break;
				}
			}
		}
		x=0;
	}
	for(int i=0;i<10;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}