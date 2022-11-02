#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

int n,m;
int a[110][110];
int b[110],c[110];
int ans=-1,nnm;

bool check(int t)
{
	b[1]=t;
	for (int i=1;i<=m;i++)
	{
		c[i]=a[1][i]-b[1];
		if (c[i]<0)	return false;
	}
	for (int i=1;i<=n;i++)
	{
		b[i]=a[i][1]-c[1];
		if (b[i]<0)	return false;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (a[i][j]!=b[i]+c[j])	return false;
	return true;
}
int q;
void outit()
{
	q=0;
	for (int i=1;i<=n;i++)	q+=b[i];
	for (int i=1;i<=m;i++)	q+=c[i];
	printf("%d\n",q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=b[i];j++)	printf("row %d\n",i);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=c[i];j++)	printf("col %d\n",i);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)	scanf("%d",&a[i][j]);
	for (int i=0;i<=a[1][1];i++)
		if (check(i))
		{
			int QAQ=0;
			for (int i=1;i<=n;i++)	QAQ+=b[i];
			for (int i=1;i<=m;i++)	QAQ+=c[i];
			if (ans==-1 || ans>QAQ)	ans=QAQ,nnm=i;
		}
	if (ans==-1)	{printf("-1\n");return 0;}
	check(nnm);
	outit();
	return 0;
}