#include<iostream>
using namespace std;
int T,N,M;
int A[50][50];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N/2;i++)for(int j=0;j<M/2;j++)
		{
			if(i+j&1)
			{
				A[i*2][j*2]=0;
				A[i*2][j*2+1]=1;
				A[i*2+1][j*2]=1;
				A[i*2+1][j*2+1]=0;
			}
			else
			{
				A[i*2][j*2]=1;
				A[i*2][j*2+1]=0;
				A[i*2+1][j*2]=0;
				A[i*2+1][j*2+1]=1;
			}
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)cout<<A[i][j]<<(j+1==M?"\n":" ");
		}
	}
}