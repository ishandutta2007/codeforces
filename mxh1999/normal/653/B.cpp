#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

#define maxn 1010
int n,m;
int mjy;
char a[maxn][5],b[maxn][5],c[maxn],ch;

void check()
{
	int j;
	char ch=c[1];
	for (int i=2;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		if (a[j][1]==ch && a[j][2]==c[i])
		{
			ch=b[j][1];
			break;
		}
		if (j>m)	return;
	}
	if (ch=='a')	mjy++;
}
void dfs(int t)
{
	if (t>n)
	{
		check();
		return;
	}
	for (int i=0;i<6;i++)
	{
		c[t]='a'+i;
		dfs(t+1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)	scanf("%s%s",a[i]+1,b[i]+1);
	dfs(1);
	printf("%d\n",mjy);
}