#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		int sum=0;
		if(n==1)
		{
			sum = 0; 
		}else if(n==2)
		{
			sum = 1;
		}else if(n==3||n%2==0)
		{
			sum = 2;
		}else
		{
			sum = 3;
		}
		cout<<sum<<endl;
	}
}