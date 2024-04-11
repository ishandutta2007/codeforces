#include<iostream>
#include<cstdio>
using namespace std;
int N,M;
int a[200][200],b[200][200];
int ah[200],aw[200];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)scanf("%d",&a[i][j]);
	}
	if(N==1)
	{
		puts("YES");
		puts("0");
		for(int j=0;j<M;j++)printf("%d",a[0][j]);
		puts("");
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		int id=!i;
		for(int j=0;j<N;j++)for(int k=0;k<M;k++)b[j][k]=a[j][k];
		for(int j=0;j<M;j++)
		{
			if(b[id][j])
			{
				for(int k=0;k<N;k++)b[k][j]=1-b[k][j];
				aw[j]=1;
			}
			else aw[j]=0;
		}
		bool ans=1;
		for(int j=0;j<i;j++)
		{
			bool f=1;
			for(int k=1;k<M;k++)f&=b[j][k-1]==b[j][k];
			if(!f)
			{
				ans=0;
				break;
			}
			if(b[j][0])ah[j]=1;
			else ah[j]=0;
		}
		for(int j=i+1;j<N;j++)
		{
			bool f=1;
			for(int k=1;k<M;k++)f&=b[j][k-1]==b[j][k];
			if(!f)
			{
				ans=0;
				break;
			}
			if(!b[j][0])ah[j]=1;
			else ah[j]=0;
		}
		if(!ans)continue;
		int cnt=0;
		for(int j=1;j<M;j++)
		{
			cnt+=b[i][j-1]!=b[i][j];
		}
		if(cnt>1)continue;
		if(cnt==1&&b[i][0])ah[i]=1;
		else ah[i]=0;
		puts("YES");
		for(int i=0;i<N;i++)printf("%d",ah[i]);
		puts("");
		for(int i=0;i<M;i++)printf("%d",aw[i]);
		puts("");
		return 0;
	}
	puts("NO");
}