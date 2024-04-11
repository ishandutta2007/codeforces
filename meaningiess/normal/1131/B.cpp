#include<iostream>
using namespace std;
int main()
{
	int n,i,x,y,nx=0,ny=0,ans=1;cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x>>y;if (x==nx && y==ny) continue;
		ans+=max(min(x,y)-max(nx,ny)+(nx!=ny),0);
		nx=x;ny=y;
	}cout<<max(ans,1);
}