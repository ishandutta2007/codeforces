#include<cstdio>
using namespace std;
int R,C;
int B[1111];
int A[555][555];
main()
{
	scanf("%d%d",&R,&C);
	if(R==1&&C==1)
	{
		puts("0");
		return 0;
	}
	if(R==1)
	{
		for(int i=0;i<C;i++)A[0][i]=i+2;
	}
	else if(C==1)
	{
		for(int i=0;i<R;i++)A[i][0]=i+2;
	}
	else
	{
		for(int i=0;i<R;i++)for(int j=0;j<C;j++)A[i][j]=(i+1)*(R+j+1);
	}
	for(int i=0;i<R;i++)for(int j=0;j<C;j++)printf("%d%c",A[i][j],j+1==C?'\n':' ');
}