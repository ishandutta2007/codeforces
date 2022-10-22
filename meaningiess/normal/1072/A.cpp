#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,k,i,x,y,ans=0;cin>>n>>m>>k;x=n,y=m;
	for (i=1;i<=k;i++)
	{
		ans+=2*(x-1)+2*(y-1);x-=4;y-=4;
	}
	cout<<ans;
}