#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[2000],l,r;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)cnt+=a[i]>a[j];
	}
	bool f=cnt%2>0;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&l,&r);
		long long k=r-l;
		if(k*(k+1)/2%2>0)f=!f;
		cout<<(f?"odd":"even")<<endl;
	}
}