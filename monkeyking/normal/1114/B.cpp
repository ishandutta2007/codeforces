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
#define abs(a) (a>0?a:-a)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m,k;
int a[200005];
pii fuck[200005];
bool use[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		fuck[i]=mp(a[i],i);
	}
	sort(fuck,fuck+n);
	reverse(fuck,fuck+n);
	ll res=0;
	for(int i=0;i<m*k;i++)
	{
		use[fuck[i].second]=true;
		res+=fuck[i].first;
	}
	cout<<res<<endl;
	res=0;
	vector <int> vec;
	for(int i=0;i<n;i++)
	{
		res+=use[i];
		if(res==m) vec.push_back(i+1),res=0;
	}
	if(res==m) vec.push_back(n);
	vec.pop_back();
	for(auto x:vec)
	{
		cout<<x<<' ';
	}
	cout<<endl;
	return 0;
}