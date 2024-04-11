#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair 
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
bool pr[1000005];
int p[1000005];

void init()
{
	for(int i=2;i<sqrt(1000005);i++)
	{
		for(int j=2;j<=1000005/i;j++)
		{
			pr[i*j]=true;
		}
	}
	int s=0;
	for(int i=2;i<1000005;i++)
	{
		if(!pr[i])
		{
			p[s++]=i;
		}
	}
}

bool prime(int x)
{
	for(int i=0;p[i]<=sqrt(x);i++)
	{
		if(x%p[i]==0) return false; 
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	init();
	int n;
	cin>>n;
	rep(n)
	{
		long long t;
		scanf("%I64d",&t);
		if(t==1)
		{
			cout<<"NO\n";
			continue;
		}
		if((ll)sqrt(t)*(ll)sqrt(t)!=t)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<(prime(sqrt(t))?"YES\n":"NO\n");
	}
	return 0;
}//123