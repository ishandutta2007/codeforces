#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <assert.h>
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
int a[20005];
int n;
int res[20005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int b=0;
	int res=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		int t=a[i]/2;
		if(a[i]%2==0)
		{
			cout<<a[i]/2<<endl;
			res+=a[i]/2;
		}
		else
		{
			if(t*2+1==a[i])
			{
				if(b==0)
				{
					b++;
					cout<<t+1<<endl;
					res+=t+1;
				}
				else
				{
					b--;
					cout<<t<<endl;
					res+=t;
				}
			}
			else
			{
				if(b==1)
				{
					b--;
					cout<<t-1<<endl;
					res+=t-1;
				}
				else
				{
					b++;
					cout<<t<<endl;
					res+=t;
				}
			}
		}
	}
	assert(res==0);
	return 0;
}