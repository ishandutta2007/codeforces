#include<iostream>
#include<algorithm>
using namespace std;
int N,A[1<<17];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	int id=2;
	while(id<N&&A[2]==A[id])id++;
	if(A[1]<A[2])
	{
		cout<<id-2<<endl;
	}
	else if(A[0]<A[1])
	{
		long long t=id-1;
		cout<<t*(t-1)/2<<endl;
	}
	else
	{
		long long t=id;
		cout<<t*(t-1)*(t-2)/6<<endl;
	}
}