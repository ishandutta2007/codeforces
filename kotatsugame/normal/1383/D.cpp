#include<cstdio>
#include<algorithm>
using namespace std;
int N,M;
int A[300][300],B[300][300];
int R[300],C[300];
bool usd[250*250+5];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)scanf("%d",&A[i][j]);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)R[i]=max(R[i],A[i][j]);
	}
	for(int j=0;j<M;j++)
	{
		for(int i=0;i<N;i++)C[j]=max(C[j],A[i][j]);
	}
	sort(R,R+N);
	sort(C,C+M);
	reverse(R,R+N);
	reverse(C,C+M);
	int ri=0,ci=0;
	while(ri<N||ci<M)
	{
		if(R[ri]==C[ci])
		{
			B[ri][ci]=R[ri];
			usd[R[ri]]=true;
			ri++;
			ci++;
		}
		else if(R[ri]<C[ci])
		{
			B[ri-1][ci]=C[ci];
			usd[C[ci]]=true;
			ci++;
		}
		else
		{
			B[ri][ci-1]=R[ri];
			usd[R[ri]]=true;
			ri++;
		}
	}
	int id=1;
	ri--,ci--;
	while(ri>=0&&ci>=0)
	{
		if(R[ri]<=C[ci])
		{
			for(int k=0;k<=ci;k++)if(B[ri][k]==0)
			{
				while(usd[id])id++;
				B[ri][k]=id;
				usd[id]=true;
			}
			ri--;
		}
		else
		{
			for(int k=0;k<=ri;k++)if(B[k][ci]==0)
			{
				while(usd[id])id++;
				B[k][ci]=id;
				usd[id]=true;
			}
			ci--;
		}
	}
	bool check=true;
	for(int i=0;i<N;i++)
	{
		int mR=0;
		for(int j=0;j<M;j++)mR=max(mR,B[i][j]);
		if(mR!=R[i])check=false;
	}
	for(int j=0;j<M;j++)
	{
		int mC=0;
		for(int i=0;i<N;i++)mC=max(mC,B[i][j]);
		if(mC!=C[j])check=false;
	}
	if(check)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)printf("%d%c",B[i][j],j+1==M?'\n':' ');
		}
	}
	else puts("-1");
}