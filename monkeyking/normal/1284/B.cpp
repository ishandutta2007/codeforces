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
#include <bitset>
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
vector <int> vec[100005];
vector <int> v;

bool de(int id)
{
	for(int i=0;i<(int)vec[id].size()-1;i++)
	{
		if(vec[id][i+1]>vec[id][i]) return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n;
	int len,x;
	for(int i=0;i<n;i++)
	{
		cin>>len;
		for(int j=0;j<len;j++)
		{
			cin>>x;
			vec[i].push_back(x);
		}
	}
	ll res=0;
	len=0;
	for(int i=0;i<n;i++)
	{
		if(de(i))
		{
			vec[len++]=vec[i];
		}
		else
		{
		}
	}
	res=1LL*n*n-1LL*len*len;
	n=len;
	for(int i=0;i<n;i++)
	{
		v.push_back(vec[i][0]);
	}
	sort(all(v));
	for(int i=0;i<n;i++)
	{
		x=vec[i][(int)(vec[i].size())-1];
		res+=(int)v.size()-(int)(upper_bound(all(v),x)-v.begin());
	}
	cout<<res<<endl;
	return 0;
}