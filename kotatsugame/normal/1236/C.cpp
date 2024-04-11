#include<iostream>
using namespace std;
int N;
int A[300][300];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<N;j++)A[j][i]=i*N+j+1;
		}
		else
		{
			for(int j=N;j--;)A[j][i]=i*N+N-j;
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)cout<<A[i][j]<<(j==N-1?"\n":" ");
	}
}