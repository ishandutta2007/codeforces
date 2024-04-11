#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int q;
	int i;
	cin>>q;
	long long n[q],a[q],b[q];
	for(i=1;i<=q;i++)
	{
		cin>>n[i]>>a[i]>>b[i];
	}
	for(i=1;i<=q;i++)
	{
		if(n[i]%2)
		{
			if(a[i]*2>b[i])
			{
				cout<<b[i]*(n[i]-1)/2+a[i]<<endl;
			}
			else
			{
				cout<<a[i]*n[i]<<endl;
			}
	    }
	    else
	    {
	    	if(a[i]*2>b[i])
			{
				cout<<b[i]*n[i]/2<<endl;
			}
			else
			{
				cout<<a[i]*n[i]<<endl;
			}
	    }
	}
	return 0;
}