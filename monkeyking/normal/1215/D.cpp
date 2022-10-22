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
char c[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	scanf("%s",c);
	int sumnum=0,sumw=0;
	for(int i=0;i<n/2;i++)
	{
		if(c[i]=='?')
		{
			sumw++;
		}
		else
		{
//			cout<<(int)c[i]<<' '<<(int)'0'<<endl;
			sumnum+=c[i]-'0';
		}
	}
	for(int i=n/2;i<n;i++)
	{
		if(c[i]=='?')
		{
			sumw--;
		}
		else
		{
			sumnum-=c[i]-'0';
		}
	}
	if(-sumw/2*9==sumnum) cout<<"Bicarp\n";else cout<<"Monocarp\n";
	return 0;
}