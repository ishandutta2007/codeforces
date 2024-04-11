#include<iostream>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int T,N,A[40];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int g=0;
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
		{
			int d=A[j]-A[i];
			if(d<0)d=-d;
			g=gcd(d,g);
		}
		if(g==0)g=-1;
		cout<<g<<"\n";
	}
}