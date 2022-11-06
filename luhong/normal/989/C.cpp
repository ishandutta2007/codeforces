#include<iostream>
#include<cstdio>
using namespace std;
int mp[52][52];
int main()
{
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=50;i++)mp[1][i]=1,mp[50][i]=2;
	for(int j=1;j<=50;j++)for(int i=2;i<50;i++)
	{
		if(j%6==2)mp[i][j]=1;
		if(j%6==3)mp[i][j]=2;
		if(j%6==5)mp[i][j]=2;
		if(j%6==0)mp[i][j]=1;
	}
	a--;b--;
	for(int j=1;j<=49;j++)
	{
		if(j%3==1)
		{
			if(a>0||b>0)
			for(int i=2;i<50;i+=2)
			{
				if(mp[i][j+1]==1)
				{
					if(b>0){mp[i][j]=2;if(c>0)mp[i+1][j]=3,c--;else if(d>0)mp[i+1][j]=4,d--;else mp[i+1][j]=1;if(i!=49)b--;}
					else mp[i][j]=mp[i+1][j]=1;
				}
				if(mp[i][j+1]==2)
				{
					if(a>0){mp[i][j]=1;if(c>0)mp[i+1][j]=3,c--;else if(d>0)mp[i+1][j]=4,d--;else mp[i+1][j]=2;if(i!=2)a--;}
					else mp[i][j]=mp[i+1][j]=2;
				}
			}
			else if(c>0)
			for(int i=2;i<50;i+=2)
			{
				if(mp[i][j+1]==1)
				{
					if(c>0){mp[i][j]=3;mp[i+1][j]=1;c--;}
					else mp[i][j]=mp[i+1][j]=1;
				}
				if(mp[i][j+1]==2)
				{
					if(c>0){mp[i][j]=3;mp[i+1][j]=2;c--;}
					else mp[i][j]=mp[i+1][j]=2;
				}
			}
			else if(d>0)
			for(int i=2;i<50;i+=2)
			{
				if(mp[i][j+1]==1)
				{
					if(d>0){mp[i][j]=4;mp[i+1][j]=1;d--;}
					else mp[i][j]=mp[i+1][j]=1;
				}
				if(mp[i][j+1]==2)
				{
					if(d>0){mp[i][j]=4;mp[i+1][j]=2;d--;}
					else mp[i][j]=mp[i+1][j]=2;
				}
			}
			else
			for(int i=2;i<50;i+=2)
			{
				if(mp[i][j+1]==1)
				{
					mp[i][j]=mp[i+1][j]=1;
				}
				if(mp[i][j+1]==2)
				{
					mp[i][j]=mp[i+1][j]=2;
				}
			}
		}
	}
	puts("50 49");
	for(int i=1;i<=50;i++,puts(""))for(int j=1;j<=49;j++)printf("%c",mp[i][j]-1+'A');
	return 0;
}