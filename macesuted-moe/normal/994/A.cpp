#include<iostream>

using namespace std;

int n,m,a[11],b[11],t,i;

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;++i)cin>>a[i];
    for(i=1;i<=m;++i)
    {
		cin>>t;
   	 	b[t]=1;
	}
    for(i=1;i<=n;++i)
    {
		if(b[a[i]]==1)
    	cout<<a[i]<<' ';
	}
    return 0;
}