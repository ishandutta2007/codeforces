#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin>>t; 
	while(t--)
	{
		char a[10] = {0};
		cin>>a;
		int sum = 0;
		
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]!=0)
			{
				if(int(a[i] +1 -'1')*pow(10,strlen(a)-i-1) !=0) 
				 {
				 	sum++;
				 }
			}
		}
		cout<<sum<<endl;
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]!=0)
			{
				if(int(a[i] +1 -'1')*pow(10,strlen(a)-i-1) !=0) 
				 {
				 	cout<<int(a[i] +1 -'1')*pow(10,strlen(a)-i-1)<<" ";
				 }
			}
		}
		cout<<endl; 
	}
 }