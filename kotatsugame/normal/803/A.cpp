#include<iostream>
using namespace std;
int N,K;
int A[100][100];
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)for(int j=i;j<N;j++)
	{
		if(i==j)
		{
			if(K>0)K--,A[i][j]=1;
		}
		else
		{
			if(K>1)K-=2,A[i][j]=A[j][i]=1;
		}
	}
	if(K>0)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)cout<<A[i][j]<<(j+1==N?"\n":" ");
	}
}