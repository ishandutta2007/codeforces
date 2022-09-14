#include<cstdio>
using namespace std;
int N;
int X[5050],Y[5050];
bool ex[5050];
main()
{
	scanf("%d",&N);
	int id=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		ex[i]=true;
		if(X[id]>X[i]||X[id]==X[i]&&Y[id]>Y[i])id=i;
	}
	printf("%d",id+1);
	ex[id]=false;
	for(int i=1;i<N;i++)
	{
		int nxt=-1;
		long long dist=-1;
		for(int j=0;j<N;j++)if(ex[j])
		{
			long long x=X[id]-X[j],y=Y[id]-Y[j];
			long long d=x*x+y*y;
			if(dist<d)dist=d,nxt=j;
		}
		printf(" %d",nxt+1);
		ex[nxt]=false;
		id=nxt;
	}
	puts("");
}