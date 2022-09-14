#include<iostream>
using namespace std;
int N,A[100];
main()
{
	cin>>N;
	int sum=0;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		sum+=A[i];
	}
	int now=A[0];
	int cnt=0;
	for(int i=1;i<N;i++)
	{
		if(A[i]*2<=A[0])
		{
			now+=A[i];
			cnt++;
		}
	}
	if(now*2>sum)
	{
		cout<<cnt+1<<endl;
		cout<<1;
		for(int i=1;i<N;i++)
		{
			if(A[i]*2<=A[0])
			{
				cout<<" "<<i+1;
			}
		}
		cout<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
}