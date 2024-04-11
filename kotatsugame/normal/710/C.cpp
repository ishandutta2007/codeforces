#include<iostream>
using namespace std;
int N;
int A[50][50];
main()
{
	cin>>N;
	int i=0,j=0;
	int f=2;
	while(f<N*N)
	{
		A[i][j]=f;
		A[i][N-j-1]=f+2;
		A[N-i-1][j]=f+4;
		A[N-i-1][N-j-1]=f+6;
		f+=8;
		j++;
		if(j==N/2)i++,j=0;
	}
	f=-1;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)cout<<(A[i][j]?:(f+=2))<<(j+1==N?"\n":" ");
	}
}