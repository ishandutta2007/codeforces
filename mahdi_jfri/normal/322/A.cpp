#include<iostream>
using namespace std;
int main()
{
		int a[110],b[110],n,m,x=1,sum1=0,j=1;
		cin>>n>>m;
		sum1=n+m-1;
		cout<<sum1<<endl;
		while(j<=m)
		{
			cout<<"1 "<<j<<endl;
				j++;
		}
		for(int i=2;i<=n;i++)
		cout<<i<<" 1"<<endl;
}