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
int n;
int a[200005];
pair<int,int> s[200005];
int seq[105];

bool compare(pii a,pii b)
{
	if(a.first!=b.first) return a.first>b.first;
	return a.second<b.second;
}

int main()
{
// 	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		s[i].first=a[i];
		s[i].second=i;
	}
	sort(s,s+n,compare);
	int q;
	cin>>q;
	while(q--)
	{
		int k,pos;
		cin>>k>>pos;
		memset(seq,0,sizeof(seq));
		for(int i=0;i<k;i++)
		{
			seq[s[i].second]=1;
		}
		int t=0;
		for(int i=0;i<n;i++)
		{
			if(seq[i]) t++;
			if(t==pos)
			{
				cout<<a[i]<<endl;
				break;
			}
		}
	}
	return 0;
}