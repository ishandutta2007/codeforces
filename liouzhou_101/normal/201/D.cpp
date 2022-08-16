#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int INF=1000000000;

int n,c;
char s[20][20];
int len[20];

void init()
{
	cin>>n;
	c=n*(n-1)/2;
	for (int i=1;i<=n;++i)
	{
		cin>>s[i];
		len[i]=strlen(s[i]);
	}
}

int v[500010];
int w[20];
int p[500010][20];
int F[1<<15][110];

void work()
{
	int Test;
	cin>>Test;
	int ans=-1,get;
	for (int T=1;T<=Test;++T)
	{
		int k;
		cin>>k;
		for (int i=1;i<=k;++i)
		{
			char t[12];
			scanf("%s",t);
			int m=strlen(t);
			v[i]=0;
			for (int j=1;j<=n;++j)
				if (len[j]==m)
				{
					int flag=0;
					for (int x=0;x<m;++x)
						if (s[j][x]!=t[x])
						{
							flag=1;
							break;
						}
					if (!flag) v[i]|=1<<(j-1);
				}
		}
		for (int i=1;i<=n;++i)
			w[i]=INF;
		for (int i=k;i>=0;--i)
		{
			for (int j=1;j<=n;++j)
				p[i][j]=w[j];
			for (int j=1;j<=n;++j)
				if (v[i]&(1<<(j-1)))
					w[j]=i;
		}
		for (int i=0;i<(1<<n);++i)
			for (int j=0;j<=c;++j)
				F[i][j]=INF;
		F[0][0]=0;
		for (int i=0;i<(1<<n);++i)
			for (int j=0;j<=c;++j)
			{
				if (F[i][j]==INF) continue;
				int t=0;
				for (int x=1;x<=n;++x)
				{
					if (i&(1<<(x-1)))
					{
						++t;
						continue;
					}
					F[i|(1<<(x-1))][j+t]=min(F[i|(1<<(x-1))][j+t],p[F[i][j]][x]);
				}
			}
		for (int i=c;i>ans;--i)
		{
			if (F[(1<<n)-1][i]!=INF)
			{
				ans=i;
				get=T;
				break;
			}
		}
	}
	if (ans==-1)
		puts("Brand new problem!");
	else
	{
		printf("%d\n[:",get);
		for (int i=0;i<=ans;++i)
			putchar('|');
		puts(":]");
	}
}

int main()
{
	init();
	work();
	return 0;
}