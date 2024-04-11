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
int a[105];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0,seat=0;
	vector <int> vec;
	vec.push_back(0);
	sum=seat=a[0];
	for(int i=1;i<n;i++)
	{
		sum+=a[i];
		if(a[i]*2<=a[0]) seat+=a[i],vec.push_back(i);
	}
	if(seat>sum-seat)
	{
		cout<<vec.size()<<endl;
		for(auto x:vec)
		{
			cout<<x+1<<' ';
		}
		cout<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}