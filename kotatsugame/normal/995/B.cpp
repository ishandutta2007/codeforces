#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
int A[200];
int L[100],R[200];
main()
{
	cin>>N;
	for(int i=0;i<2*N;i++)
	{
		cin>>A[i];
	}
	int ans=0;
	for(int i=0;i<2*N;i+=2)
	{
		int a=A[i];
		int j=i+1;
		while(A[j]!=a)j++;
		while(j>i+1)
		{
			swap(A[j-1],A[j]);
			ans++;
			j--;
		}
	}
	cout<<ans<<endl;
}