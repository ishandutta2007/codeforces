#include<iostream>
using namespace std;
int H,W;
int A[20][20];
main()
{
	int T;cin>>T;
	for(;T--;)
	{
		cin>>H>>W;
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)A[i][j]=0;
		for(int j=0;j<W;j+=2)A[0][j]=1;
		for(int i=2;i<H-1;i+=2)A[i][0]=A[i][W-1]=1;
		for(int j=0;j<W;j++)
		{
			if(A[H-2][j])continue;
			if(j>0&&(A[H-1][j-1]||A[H-2][j-1]))continue;
			if(j+1<W&&A[H-2][j+1])continue;
			A[H-1][j]=1;
		}
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)cout<<A[i][j];
			cout<<"\n";
		}
	}
}