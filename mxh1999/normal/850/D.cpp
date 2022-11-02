#include<bits/stdc++.h>
using namespace std;

int m;
bool f[32][70][2010];
int pre[32][70][2010];
int n;
int a[32];
void prepare()
{
	f[0][0][0]=true;
	f[1][1][a[1]]=true;
	pre[1][1][a[1]]=a[1];
	for (int i=1;i<=m;i++)
	{
		for (int j=i;j<=61;j++)
			for (int k=j*(j-1)/2;k<=2000;k++)
			if (f[i][j][k])
			{
				int q=k+a[i];
				if (q>=j*(j+1)/2)
				{
					f[i][j+1][q]=true;
					pre[i][j+1][q]=i;
				}
			}
		if (i<m)
		{
			for (int j=i;j<=61;j++)
				for (int k=j*(j-1)/2;k<=2000;k++)
				if (f[i][j][k])
				{
					int q=k+a[i+1];
					if (q>=j*(j+1)/2)
					{
						f[i+1][j+1][q]=true;
						pre[i+1][j+1][q]=i;
					}
				}
		}
	}
}
int ans[100];
int remain[100];
pair<int,int> ha[100];
int b[100][100];
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first<b.first;
}
void getans(int x)
{
	int now1=m,now2=x*(x-1)/2;
	while (x>0)
	{
		ans[++n]=a[now1];
		int tmp=pre[now1][x][now2];
		now2-=a[now1];
		x--;
		now1=tmp;
	}
	sort(ans+1,ans+n+1);
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		for (int j=i+1;j<=n;j++)
			ha[++cnt]=make_pair(ans[j],j);
		sort(ha+1,ha+cnt+1,cmp);
		for (int j=1;j<=ans[i];j++)
			b[i][ha[j].second]=1;
		for (int j=ans[i]+1;j<=cnt;j++)
		{
			b[ha[j].second][i]=1;
			ans[ha[j].second]--;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%d",b[i][j]);
		printf("\n");
	}
}
int main()
{
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	prepare();
	for (int i=m;i<=61;i++)
		if (f[m][i][i*(i-1)/2])
		{
			printf("%d\n",i);
			getans(i);
			return 0;
		}
	printf("=(\n");
	return 0;
}