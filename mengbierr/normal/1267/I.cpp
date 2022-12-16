#include<bits/stdc++.h>
using namespace std;
int comp[233][233];//1:a>b
int good[233],bad[233];
inline int ask(int a,int b)
{
	assert(a!=b);
	if(comp[a][b])return comp[a][b];
	printf("? %d %d\n",a,b);
	fflush(stdout);
	char ch;
	scanf(" %c",&ch);
	if(ch=='>')comp[a][b]=1,comp[b][a]=-1;
	else comp[a][b]=-1,comp[b][a]=1;
	return comp[a][b];
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)for(int j=1;j<=n*2;j++)comp[i][j]=0;
		int ok=0,a=1,b=2,c=3,d=4;
		while(!ok)
		{
//			cerr<<"gao "<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			if(ask(a,b)<0)swap(a,b);
			if(ask(c,d)<0)swap(c,d);
			if(ask(b,d)<0)swap(b,d);
			int tg=0,tb=0;
			for(int i=1;i<=n*2;i++)
			{
				if(i==d)continue;
				if(ask(i,d)>0)good[++tg]=i;
				else bad[++tb]=i;
			}
			if(tb>=n-1)
			{
				ok=1;
				for(int i=1;i<=tb;i++)
				{
					for(int j=i+1;j<=tb;j++)
					{
						ask(bad[i],bad[j]);
					}
				}
			}
			else
			{
				for(int i=1;i<=tg;i++)
				{
					if(good[i]!=a&&good[i]!=b&&good[i]!=c)
					{
						d=good[i];
						break;
					}
				}
				if(comp[a][c])swap(b,c);
				else if(comp[b][c])swap(a,c);
			}
		}
		printf("!\n");
		fflush(stdout);
	}
	return 0;
}