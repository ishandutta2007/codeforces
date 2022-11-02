#include<bits/stdc++.h>
using namespace std;

const int maxn=210;
string pre[maxn],suf[maxn];
int f[maxn][1024][10];
string tmp;
int n,m;

void prepare(int id)
{
	if (tmp.length()<=10)
	{
		pre[id]=tmp;
		suf[id]=tmp;
	}	else
	{
		for (int i=0;i<10;i++)
			pre[id]+=tmp[i];
		for (int i=10;i>=1;i--)
			suf[id]+=tmp[tmp.length()-i];
	}
	for (int i=0;i<tmp.length();i++)
	{
		int has=0;
		for (int j=0;j<10;j++)
			if (i+j<tmp.length())
			{
				has=has*2+tmp[i+j]-'0';
				f[id][has][j]=true;
			}
	}
}
void Union(int x,int y)
{
	n++;
	pre[n]=pre[x];
	for (int i=0;i<pre[y].length() && pre[n].length()<10;i++)
			pre[n]+=pre[y][i];
	if (suf[y].length()==10)	suf[n]=suf[y];
	else
	{
		if (suf[y].length()+suf[x].length()<=10)	suf[n]=suf[x]+suf[y];
		else
		{
			for (int j=10-suf[y].length();j>=1;j--)
				suf[n]+=suf[x][suf[x].length()-j];
			suf[n]+=suf[y];
		}
	}
	for (int len=0;len<10;len++)
		for (int j=0;j<(1<<(len+1));j++)
			f[n][j][len]=f[x][j][len]|f[y][j][len];
	tmp=suf[x]+pre[y];
	for (int i=0;i<tmp.length();i++)
	{
		int has=0;
		for (int j=0;j<10;j++)
			if (i+j<tmp.length())
			{
				has=has*2+tmp[i+j]-'0';
				f[n][has][j]=true;
			}
	}
	for (int len=0;len<10;len++)
		for (int j=0;j<(1<<(len+1));j++)
			if (!f[n][j][len])
			{
				printf("%d\n",len);
				return;
			}
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>tmp;
		prepare(i);
	}
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Union(x,y);
	}
	return 0;
}