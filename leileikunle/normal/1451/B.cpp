#include <bits/stdc++.h>
using namespace std;
int same(int x,int y,string a,int len)
{
	int c = a[x-1];
	int d = a[y-1];
	for(int i=0;i<x-1;i++)
	{
		if(a[i] == c) return 1;
	}
	for(int i=len-1;i>y-1;i--)
	{
		if(a[i] == d) return 1;
	}
	return 0;
}
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int len; int n; cin>>len>>n;
		string a; cin>>a;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			if(same(x,y,a,len))
			{
				cout<<"YES"<<endl;
			}else {
				cout<<"NO"<<endl;
			}
		}
	}
}