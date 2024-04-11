#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N,x[1<<17],k;
bool ok[1<<17][3];
bool ap[1<<17];
main()
{
	scanf("%d%d",&N,&k);
	for(int i=0;i<k;i++)scanf("%d",x+i);
	for(int i=1;i<=N;i++)
	{
		ok[i][1]=1;
		if(i<N)ok[i][2]=1;
		if(i>1)ok[i][0]=1;
	}
	for(int i=k;i--;)
	{
		ok[x[i]][1]=0;
		if(ap[x[i]+1])ok[x[i]][2]=0;
		if(ap[x[i]-1])ok[x[i]][0]=0;
		ap[x[i]]=1;
	}
	int ans=0;
	for(int i=1;i<=N;i++)for(int j=0;j<3;j++)ans+=ok[i][j];
	printf("%d\n",ans);
}