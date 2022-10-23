#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int N,A[20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		int G=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			G=gcd(G,A[i]);
		}
		if(G==1)
		{
			cout<<"0\n";
			continue;
		}
		else if(gcd(G,N)==1)
		{
			cout<<"1\n";
			continue;
		}
		else if(gcd(G,N-1)==1)
		{
			cout<<"2\n";
			continue;
		}
		cout<<"3\n";
	}
}