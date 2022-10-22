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

bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int edge;
	for(int i=n;i<=i+(n/2);i++)
	{
		bool ok=false;
		if(isprime(i))
		{
			ok=true;
			edge=i;
			break;
		}
	}
	cout<<edge<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<(i+1)<<' '<<((i+1)%n+1)<<endl;
	}
	int base=n/2;
	for(int i=0;i<edge-n;i++)
	{
		cout<<i+1<<' '<<i+base+1<<endl;
//		cout<<(2*i+1)<<' '<<(2*i+2)<<endl;
	}
	return 0;
}