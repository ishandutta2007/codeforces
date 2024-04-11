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
#include <assert.h>
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
int n,k;
char c[2005];
char d[2005];

void solve()
{
	cin>>n>>k;
	scanf("%s",c);
	for(int i=0;i<(k-1)*2;i+=2)
	{
		d[i]='(';
		d[i+1]=')';
	}
	for(int i=(k-1)*2;i<(k-1)*2+(n-(k-1)*2)/2;i++)
	{
		d[i]='(';
	}
	for(int i=(k-1)*2+(n-(k-1)*2)/2;i<n;i++)
	{
		d[i]=')';
	}
	vector <pair<int,int> > res;
	for(int i=0;i<n;i++)
	{
		if(c[i]==d[i]) continue;
		for(int j=i+1;j<n;j++)
		{
			if(c[j]==d[i])
			{
				res.push_back(mp(i+1,j+1));
				reverse(c+i,c+j+1);
				break;
			}
		}
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
	{
		printf("%d %d\n",res[i],res[i]);
	}
	cout<<endl;
}

int main()
{
// 	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}