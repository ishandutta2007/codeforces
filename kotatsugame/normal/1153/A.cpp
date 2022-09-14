#include<iostream>
using namespace std;
int n,t;
main()
{
	cin>>n>>t;
	int id=-1,M=1e9;
	for(int i=0;i<n;i++)
	{
		int s,d;cin>>s>>d;
		int now;
		if(s>t)now=s;
		else now=s+(t-s+d-1)/d*d;
		if(M>now)
		{
			M=now;
			id=i+1;
		}
	}
	cout<<id<<endl;
}