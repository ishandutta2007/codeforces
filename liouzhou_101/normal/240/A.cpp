#include<cstdio>
#include<iostream>

using namespace std;

int m,k,n;
int a[110],b[110];
int most[110],least[110];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>m>>k;
	for (int i=1;i<=k;++i)
	{
		int x;
		scanf("%d",&x);
		++a[x];
	}
	cin>>n;
	for (int T=1;T<=n;++T)
	{
		char s[110];
		scanf("%s",s);
		int d;
		scanf("%d",&d);
		int have=0,check=0,bad=0;
		for (int i=1;i<=m;++i)
			b[i]=0;
		for (int i=1;i<=d;++i)
		{
			int x;
			scanf("%d",&x);
			if (!x)
			{
				++check;
				continue;
			}
			if (a[x])
			{
				b[x]=1;
				++have;
			}
			else
				++bad;
		}
		most[T]=min(k,have+check);
		least[T]=have+max(check-(m-k-bad),0);
	}
	for (int i=1;i<=n;++i)
	{
		int flag=0;
		for (int j=1;j<=n;++j) if (i!=j)
			if (least[i]<most[j]) flag=1;
		if (!flag)
		{
			puts("0");
			continue;
		}
		flag=0;
		for (int j=1;j<=n;++j) if (i!=j)
			if (most[i]<least[j])
				flag=1;
		if (!flag)
		{
			puts("2");
			continue;
		}
		puts("1");
	}
	return 0;
}