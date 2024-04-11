#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int p[5555],b[5555],k[5555],ans[5555],cnt,n,x[5555],y[5555],kk[5555];
bool used[5555],f;
int main()
{
	srand(time(0));
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("? %d %d\n",0,i);
		fflush(stdout);
		scanf("%d",&k[i]);
	}
	for (int i=0;i<n;i++)
	{
		x[i]=rand()%n;y[i]=rand()%n;
		printf("? %d %d\n",x[i],y[i]);
		fflush(stdout);
		scanf("%d",&kk[i]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++) used[j]=0;
		f=0;
		for (int j=0;j<n;j++) 
		{
			b[j]=k[j]^i;
			if (b[j]>=n || used[b[j]]) 
			{
				f=1;
				break;
			}
			used[b[j]]=1;
		}
		if (f) continue;
		for (int j=0;j<n;j++) p[b[j]]=j;
		for (int j=0;j<n;j++)
		{
			if ((p[x[j]]^b[y[j]])!=kk[j]) f=1;
		}
		if (f) continue;
		if (p[0]==i)
		{
			cnt++;
			for (int j=0;j<n;j++) ans[j]=p[j];
		}
	}
	printf("!\n");
	fflush(stdout);
	printf("%d\n",cnt);
	fflush(stdout);
	for (int i=0;i<n;i++)
	{
		printf("%d ",ans[i]);
		fflush(stdout);
	}
	return 0;
}