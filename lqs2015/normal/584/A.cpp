#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	if (n==1 && k==10) cout<<"-1";
	else
	{
		if (n<=8)
		{
			bool f=0;
			int t=pow(10,n-1)+1;
			while(!f)
			{
				if (t%k==0) 
				{
					cout<<t;
					return 0;
				}
				t++;
			}
		}
		else
		{
			cout<<"1";
			if (k==2 || k==4 || k==5 || k==8 || k==10) 
			{
				for (int i=1;i<n;i++) cout<<"0";
				return 0;
			}
			if (k==3 || k==6)
			{
				for (int i=1;i<n-1;i++) cout<<"0";
				cout<<"2";
				return 0;
			}
			if (k==9)
			{
				for (int i=1;i<n-1;i++) cout<<"0";
				cout<<"8";
				return 0;
        	}
        	if (k==7)
        	{
        		cout<<"4";
        		for (int i=1;i<n-1;i++) cout<<"0";
        		return 0;
        	}
		}
	}
	return 0;
}