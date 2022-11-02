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

#define maxn 11
bool b[maxn][maxn];
int num[maxn];
int f[maxn][60010];
int q[maxn];
int mxh,n,m;
int mjy;

int main()
{
	read(n),read(m),read(mxh);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		b[x][y]=b[y][x]=true;
	}
	int all=1;
	for (int i=1;i<=n;i++)
	{
		num[i]=all;
		f[1][all]=1;
		all*=3;
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<all;j++)
		if (f[i-1][j])
		{
			int now=j;
			for (int _=1;_<=n;_++)	q[_]=0;
			int _=1,maxx=1,minx=1,_num=0;
			while (now)
			{
				q[_]=now%3;
				if (q[_]==1)	minx=maxx,maxx=_;
				if (q[_]!=0)	_num++;
				_++;
				now/=3;
			}
			for (int x=minx;x<=n;x++)
			if (q[x]==0)
				for (int y=1;y<=n;y++)
				if (q[y]!=0 && b[x][y])
				{
					if (x<maxx && y!=maxx)	continue;
					if (x<maxx && _num==1)	continue;
					if (q[y]==2 || _num==1)	f[i][j+num[x]]+=f[i-1][j];else f[i][j+num[x]+num[y]]+=f[i-1][j];
				}
		}
	}
	for (int j=0;j<all;j++)
	{
		int now=j;
		for (int _=1;_<=n;_++)	q[_]=0;
		int _=1,maxx=0,_num=0;
		while (now)
		{
			q[_]=now%3;
			if (q[_]==1)	maxx++;
			if (q[_]!=0)	_num++;
			now/=3;
		}
		if (maxx==mxh && _num==n)	mjy+=f[n][j];
	}
	printf("%d\n",mjy);
	return 0;
}