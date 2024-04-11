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
int n;
vector <int> res;

void solve(int l,int r)
{
	if(l>r) return;
	if(l==r)
	{
		res.push_back(l);
		return;
	}
	if(l+1==r)
	{
		res.push_back(l);
		return;
	}
	if(l+2==r)
	{
		res.push_back(l);
		return;
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(c[l+i]==c[r-j])
			{
				res.push_back(l+i);
				res.push_back(r-j);
				solve(l+i+1,r-j-1);
				return;
			}
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	n=strlen(c);
	solve(0,n-1);
	sort(all(res));
	for(auto x:res)
	{
		putchar(c[x]);
	}
	cout<<endl;
	return 0;
}