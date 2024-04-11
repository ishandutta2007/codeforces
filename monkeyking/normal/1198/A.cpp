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
int n,k;
map <int,int> m;
vector <int> vec;
int sum[400005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	k*=8;
	k=(1<<(min((int)(k/n),20)));
	k=min(k,n);
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		m[x]++;
	}
	for(auto i:m)
	{
		vec.push_back(i.second);
	}
	sum[0]=vec[0];
	n=vec.size();
	k=min(k,n);
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+vec[i];
	}
	int res=inf;
	for(int i=0;i<n;i++)
	{
		if(i+k-1>=n) break;
		res=min(res,sum[n-1]-(sum[i+k-1]-(i?sum[i-1]:0)));
	}
	cout<<res<<endl;
	return 0;
}