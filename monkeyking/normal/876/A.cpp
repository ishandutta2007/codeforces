#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
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

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(a<=b && a<=c)
	{
		cout<<a*(n-1)<<endl;
	}
	else if(b<=a && b<=c)
	{
		cout<<b*(n-1)<<endl;
	}
	else
	{
		if(n==2)
		{
			cout<<min(a,b)<<endl;
		}
		else
		{
			cout<<min(a,b)+c*(n-2)<<endl; 
		}
	}
	return 0;
}