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

bool check(int x)
{
	vector <int> v;
	while(x)
	{
		v.push_back(x%10);
		x/=10;
	}
	sort(all(v));
	for(int i=0;i<(int)v.size()-1;i++)
	{
		if(v[i]==v[i+1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int l,r;
	cin>>l>>r;
	int res=0;
	for(int i=l;i<=r;i++)
	{
		if(check(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}