#include<iostream>
using namespace std;
int main()
{
	int n,mx=0,i,x,y;cin>>n;
	for (i=1;i<=n;i++) {cin>>x>>y;mx=max(mx,x+y);}
	cout<<mx;
}