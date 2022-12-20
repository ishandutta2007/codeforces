#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int n,cnt;bool vis[100005];int group[100005],size[100005];
struct data
{
	int num;
	int id;
	int group;
}a[100005];
int cmp(data x,data y)
{
	return x.num<y.num;
}
int cmp2(data x,data y)
{
	return x.group<y.group;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].num);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int now=i;
		if(!vis[i])
		cnt++;
		while(!vis[now])
		{
			vis[now]=1;
			a[now].group=cnt;
			now=a[now].id;
			size[cnt]++;
		}
	}
	printf("%d\n",cnt);
	sort(a+1,a+n+1,cmp2);
	int tmp=0;
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",size[i]);
		for(int j=1;j<=size[i];j++)
		{
			printf("%d ",a[++tmp].id);
		}
		puts("");
	}
}