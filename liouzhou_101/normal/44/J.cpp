#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=1010;

int n,m;
char s[MaxN][MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
}

int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int v[5];

void check(int x,int y)
{
	if (s[x][y]>0&&s[x][y]<=4)
		v[s[x][y]]=1;
}

void paint(int x1,int y1,int x2,int y2,int x3,int y3)
{
	memset(v,0,sizeof(v));
	for (int k=0;k<4;++k)
	{
		check(x1+dx[k],y1+dy[k]);
		check(x2+dx[k],y2+dy[k]);
		check(x3+dx[k],y3+dy[k]);
	}
	for (int i=1;i<=4;++i)
		if (!v[i])
		{
			s[x1][y1]=s[x2][y2]=s[x3][y3]=i;
			return;
		}
}

void work()
{
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			if (s[i][j]=='b')
			{
				puts("NO");
				return;
			}
			if (s[i][j]!='w') continue;
			if (s[i][j+1]=='b')
			{
				if (s[i][j+2]!='w')
				{
					puts("NO");
					return;
				}
				paint(i,j,i,j+1,i,j+2);
			}
			else if (s[i+1][j]=='b')
			{
				if (s[i+2][j]!='w')
				{
					puts("NO");
					return;
				}
				paint(i,j,i+1,j,i+2,j);
			}
			else
			{
				puts("NO");
				return;
			}
		}
	puts("YES");
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
			if (s[i][j]=='.')
				putchar('.');
			else
				putchar(s[i][j]+'a'-1);
		puts("");
	}
}

int main()
{
	init();
	work();
	return 0;
}