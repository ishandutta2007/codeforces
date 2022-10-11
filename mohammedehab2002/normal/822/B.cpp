#include <iostream>
using namespace std;
char a[1005],b[1005];
bool t[1005][1005];
int main()
{
	int n,m,ans=(1<<20),pos=0;
	scanf("%d%d",&n,&m);
	getchar();
	gets(a);
	gets(b);
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		{
			if (a[i]==b[x])
			t[i][x]=1;
		}
	}
	for (int i=0;i<=m-n;i++)
	{
		int mis=0;
		for (int x=i;x<i+n;x++)
		{
			if (!t[x-i][x])
			mis++;
		}
		if (mis<ans)
		{
			ans=mis;
			pos=i;
		}
	}
	printf("%d\n",ans);
	for (int i=pos;i<pos+n;i++)
	{
		if (!t[i-pos][i])
		printf("%d ",i-pos+1);
	}
}