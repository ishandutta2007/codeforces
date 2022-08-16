#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n;
char s[1000010];

int m;
int p[10010],v[10010],F[10010];

inline int find(int x)
{
	int u=lower_bound(p+1,p+m+1,x)-p;
	return (p[u]==x)?u:0;
}

void init()
{
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	for (int i=1;i<=m;++i)
	{
		char t[110];
		scanf("%s",t);
		int x=0;
		for (int j=0;j<strlen(t);++j)
			x|=1<<(t[j]-'a');
		p[i]=v[i]=x;
	}
	sort(p+1,p+m+1);
}

int q[30];

void work()
{
	for (int i=n;i>=1;--i)
	{
		int x=1<<(s[i]-'a');
		int y=(i==1)?0:1<<(s[i-1]-'a');
		for (int j=1;j<=27;++j)
			if (!q[j]||q[j]==x)
			{
				for (int k=j;k>=1;--k)
					q[k]=q[k-1];
				q[1]=x;
				break;
			}
		int u=0;
		for (int j=1;q[j]&&q[j]!=y;++j)
		{
			u|=q[j];
			int k;
			if (k=find(u)) F[k]++;
		}
	}
	for (int i=1;i<=m;++i)
		printf("%d\n",F[find(v[i])]);
}

int main()
{
	init();
	work();
	return 0;
}