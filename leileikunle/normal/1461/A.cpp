#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n+1]={0};
		for(int i=1;i<=n;i++)
		{
			if(i%3==1) cout<<'a';
			if(i%3==2) cout<<'b';
			if(i%3==0) cout<<'c';
		}
		cout<<endl;
	}
}