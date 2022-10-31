#include<iostream>
#include<cstdio>
using namespace std;
int n,m,i,j,k;
int main()
{
	cin>>n;
	m=n;
	for(i=2;i*i<=m;i++)
		if(m%i==0)
		  break;
	if(m%i!=0)
	{
		cout<<"NO";
		return 0;
	}
	j=i;
	while(m%i==0) m/=i;
	if(m==1)
	{
		cout<<"NO";
		return 0;
	}
	k=m;
	j=n/k;
	for(i=1;i<j;i++)
	   if((n-1-i*k)%j==0)
	     break;
	cout<<"YES\n2\n"<<i<<" "<<j<<"\n"<<(n-1-i*k)/j<<" "<<k;
	return 0;
}