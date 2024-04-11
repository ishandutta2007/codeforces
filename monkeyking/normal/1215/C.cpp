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
char a[200005];
char b[200005];
int n;
vector <int> v0,v1;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	scanf("%s",a);
	scanf("%s",b);
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[i]) continue;
		if(a[i]=='a') v0.push_back(i+1);else v1.push_back(i+1);
	}
	if(((int)v0.size()+(int)v1.size())&1)
	{
		cout<<"-1\n";
		return 0;
	}
	int l0=v0.size();
	int l1=v1.size();
	if(l0&1)
	{
		cout<<l0/2+l1/2+2<<endl;
	}
	else
	{
		cout<<l0/2+l1/2<<endl;
	}
	for(int i=0;i+1<l0;i+=2)
	{
		cout<<v0[i]<<' '<<v0[i+1]<<endl;
	}
	for(int i=0;i+1<l1;i+=2)
	{
		cout<<v1[i]<<' '<<v1[i+1]<<endl;
	}
	if(l0&1)
	{
		cout<<v0[l0-1]<<' '<<v0[l0-1]<<endl;
		cout<<v0[l0-1]<<' '<<v1[l1-1]<<endl;
	}
	return 0;
}