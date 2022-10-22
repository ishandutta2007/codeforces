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
const char c[]="aeiou";

int main()
{
//	freopen("input.txt","r",stdin);
	int k;
	cin>>k;
	int n=-1,m;
	for(int i=5;i*i<=k;i++)
	{
		if(k%i!=0) continue;
		if(k/i>=5)
		{
			n=i;
			m=k/i;
			break;
		}
	}
	if(n==-1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			putchar(c[(i+j)%5]);
		}
	}
	return 0;
}