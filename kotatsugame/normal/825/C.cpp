#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
int A[1000];
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		while(A[i]>K*2)K*=2,cnt++;
		if(K<A[i])K=A[i];
	}
	cout<<cnt<<endl;
}