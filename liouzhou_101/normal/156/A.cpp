#include<cstdio>
#include<cstring>

const int MaxN=2010;

char s[MaxN],t[MaxN];
int n,m,ans;

int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	ans=m=strlen(t+1);
	for (int i=1;i<=n;++i)
	{
		int tmp=0;
		for (int j=1;j<=m;++j)
		{
			if (i+j-1>n)
			{
				tmp+=(m-j+1);
				break;
			}
			if (s[i+j-1]!=t[j])
				++tmp;
		}
		if (ans>tmp) ans=tmp;
	}
	for (int i=1;i<=m;++i)
	{
		int tmp=i;
		int k=1;
		for (int j=i+1;j<=m;++j)
		{
			if (k>n)
			{
				tmp+=(m-j+1);
				break;
			}
			if (s[k]!=t[j])
				++tmp;
			++k;
		}
		if (ans>tmp) ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
}