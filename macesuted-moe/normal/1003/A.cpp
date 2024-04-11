#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a[t]++;
	}
	int maxx=0;
	for(int i=0;i<101;i++)
	{
		maxx=max(a[i],maxx);
	}
	cout<<maxx<<endl;
	return 0;
}