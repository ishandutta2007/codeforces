#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
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


void print(int k)
{
	cout<<"YES\n";
	cout<<k<<endl;
	exit(0);
}

int main()
{
//	freopen("input.txt","r",stdin);
	string c;
	cin>>c;
	int len=c.size();
	for(int i=0;i<len;i++)
	{
		c[i]-='0';
		if(c[i]%8==0)
		{
			print(c[i]);
		}
	}
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if((c[i]*10+c[j])%8==0) print(c[i]*10+c[j]);
		}
	}
//	cout<<98243<<endl;
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			for(int k=j+1;k<len;k++)
			{
				int t=c[i]*100+c[j]*10+c[k];
				if(t%8==0) print(t);
			}
		}
	}
//	cout<<23485<<endl;
	cout<<"NO\n";
	return 0;
}