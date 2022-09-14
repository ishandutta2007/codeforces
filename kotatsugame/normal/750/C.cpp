#include<iostream>
using namespace std;
main()
{
	int n;cin>>n;
	int c[200001]={},d[200000];
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x>>d[i];
		c[i+1]=c[i]+x;
	}
	int mi=1<<30,ma=-1<<30;
	for(int i=0;i<n;i++)
	{
		if(d[i]==1)mi=min(mi,c[i]);
		else ma=max(ma,c[i]);
	}
	if(mi<=ma)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(ma==-1<<30)
	{
		cout<<"Infinity"<<endl;
		return 0;
	}
	int dif;
	for(int i=0;i<n;i++)if(d[i]==2&&ma==c[i])dif=1899-ma;
	cout<<dif+c[n]<<endl;
}