#include<cstdio>
using namespace std;
int N,A[1<<17],B[1<<17];
bool ap[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		ap[A[i]]=true;
	}
	int id=0;
	for(int i=0;i<N;i++)
	{
		if(i>0&&A[i-1]<A[i])
		{
			B[i]=A[i-1];
		}
		else
		{
			while(ap[id])id++;
			B[i]=id++;
		}
		printf("%d%c",B[i],i+1==N?'\n':' ');
	}
}