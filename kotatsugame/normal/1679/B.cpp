#include<iostream>
using namespace std;
int N,Q;
int A[2<<17];
int Tm[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q;
	long long sum=0;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		sum+=A[i];
		Tm[i]=-1;
	}
	int p2x,p2tm=-2;
	for(int t=0;t<Q;t++)
	{
		int tp;cin>>tp;
		if(tp==1)
		{
			int i,x;cin>>i>>x;i--;
			if(Tm[i]>p2tm)sum-=A[i];
			else sum-=p2x;
			sum+=x;
			A[i]=x;
			Tm[i]=t;
		}
		else
		{
			int x;cin>>x;
			p2tm=t;
			p2x=x;
			sum=(long long)N*x;
		}
		cout<<sum<<"\n";
	}
}