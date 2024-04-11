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
char c[200005];

vector <int> split(char c[],char ch)
{
	vector <int> vec;
	int s=0;
	for(int i=0;i<n-1;i++)
	{
		if(c[i]!=ch) s++;
		else
		{
			vec.push_back(s+1);
			s=0;
		}
	}
	vec.push_back(s+1);
	return vec;
}

void solve()
{
	scanf("%d",&n);
	scanf("%s",c);
	vector <int> vec;
	vec=split(c,'>');
	int s=n;
	for(auto x:vec)
	{
		for(int i=s-x+1;i<=s;i++)
		{
			printf("%d ",i);
		}
		s-=x;
	}
	puts("");
	vec=split(c,'<');
	s=0;
	for(auto x:vec)
	{
		for(int i=s+x;i>=s+1;i--)
		{
			printf("%d ",i);
		}
		s+=x;
	}
	puts("");
}

int main()
{
//	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}