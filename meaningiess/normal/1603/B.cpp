#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		ll x,y;cin>>x>>y;
		if (x>y)
		{
			cout<<x+y<<endl;
		}
		else
		{
			int tp=y/x,c=y-tp*x;
			c/=2;
			cout<<y-c<<endl;
		}
	}
}
/*
y=k1k2x+(k2+1)c   c<x
y-k1x=2c
*/