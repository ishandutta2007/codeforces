#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
char s[333333],tmp[333333],anss[333333],now[333333];
int make[][2][2]={
	{{0,1},{2,3}},
	{{0,2},{1,3}},
	{{0,3},{1,2}},
	{{1,2},{0,3}},
	{{1,3},{0,2}},
	{{2,3},{0,1}},
};
char itoc[5]="AGCT";
int ctoi[100];
int ans=1e9;
main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=0;i<4;i++)ctoi[itoc[i]]=i;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)s[i*m+j]=ctoi[getchar()];
		getchar();
	}
	for(int t=0;t<6;t++)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			int nowans=1e9;
			for(int tj=0;tj<2;tj++)
			{
				int nowcnt=0;
				for(int j=0;j<m;j++)nowcnt+=s[i*m+j]!=(now[i*m+j]=make[t][i%2][(j+tj)%2]);
				if(nowans>nowcnt)
				{
					nowans=nowcnt;
					for(int j=0;j<m;j++)tmp[i*m+j]=now[i*m+j];
				}
			}
			cnt+=nowans;
		}
		if(cnt<ans)
		{
			ans=cnt;
			for(int i=0;i<n*m;i++)anss[i]=tmp[i];
		}
		cnt=0;
		for(int j=0;j<m;j++)
		{
			int nowans=1e9;
			for(int ti=0;ti<2;ti++)
			{
				int nowcnt=0;
				for(int i=0;i<n;i++)nowcnt+=s[i*m+j]!=(now[i*m+j]=make[t][j%2][(i+ti)%2]);
				if(nowans>nowcnt)
				{
					nowans=nowcnt;
					for(int i=0;i<n;i++)tmp[i*m+j]=now[i*m+j];
				}
			}
			cnt+=nowans;
		}
		if(cnt<ans)
		{
			ans=cnt;
			for(int i=0;i<n*m;i++)anss[i]=tmp[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)putchar(itoc[anss[i*m+j]]);
		putchar(10);
	}
}