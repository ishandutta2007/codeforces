#include<cstdio>
using namespace std;
int N;
int A[500][500];
main()
{
	scanf("%d",&N);
	if(N<=2)
	{
		puts("-1");
		return 0;
	}
	else if(N==3)
	{
		puts("1 2 4");
		puts("5 3 8");
		puts("9 6 7");
		return 0;
	}
	else if(N==4)
	{
		puts("4 3 6 12");
		puts("7 5 9 15");
		puts("14 1 11 10");
		puts("13 8 16 2");
		return 0;
	}
	int id=0;
	for(int j=0;j<N;j++)A[0][j]=++id;
	for(int i=N-1;i>=0;i--)
	{
		int lim=N-3;
		if((N-i)%2==1)
		{
			for(int j=1;j<lim;j++)A[j][i]=++id;
		}
		else
		{
			for(int j=lim-1;j>=1;j--)A[j][i]=++id;
		}
	}
	for(int i=0;i<N-3;i++)
	{
		if(i%2==0)
		{
			for(int j=N-3;j<N-1;j++)A[j][i]=++id;
		}
		else
		{
			for(int j=N-2;j>=N-3;j--)A[j][i]=++id;
		}
	}
	for(int j=N-4;j>=0;j--)A[N-1][j]=++id;
	A[N-3][N-3]=id+4;
	A[N-3][N-2]=id+8;
	A[N-3][N-1]=id+7;
	A[N-2][N-3]=id+2;
	A[N-2][N-2]=id+3;
	A[N-2][N-1]=id+6;
	A[N-1][N-3]=id+1;
	A[N-1][N-2]=id+5;
	A[N-1][N-1]=id+9;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)printf("%d%c",A[i][j],j+1==N?'\n':' ');
	}
}