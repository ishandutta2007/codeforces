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
int go[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int time;
	cin>>time;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=a;j<=200000;j+=b)
		{
			go[j]=i+1;
		}
	}
	for(int i=time;i<=200000;i++)
	{
		if(go[i]!=0) over(go[i]);
	}
	return 0;
}