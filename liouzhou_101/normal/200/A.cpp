#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=2010;
const int INF=1000000000;

int n,m,k,d,x,y,px,py;
int u[MaxN][MaxN],L[MaxN][MaxN],R[MaxN][MaxN];

int getabs(int x)
{
	return (x>=0)?x:-x;
}

void check(int tx,int ty)
{
	int t=getabs(x-tx)+getabs(y-ty);
	if (t<d||t==d&&make_pair(tx,ty)<make_pair(px,py))
	{
		d=t;
		px=tx;
		py=ty;
	}
}

void answer(int px,int py)
{
	printf("%d %d\n",px,py);
	u[px][py]=1;
	L[px][py]=(py==1)?INF:L[px][py-1];
	R[px][py]=(py==m)?INF:R[px][py+1];
	for (int i=py;u[px][i]&&i<=m;++i)
		L[px][i]=L[px][py];
	for (int i=py;u[px][i]&&i>=1;--i)
		R[px][i]=R[px][py];
}

int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			L[i][j]=R[i][j]=j;
	while (k--)
	{
		scanf("%d%d",&x,&y);
		d=INF;
		for (int i=0;i<=d;++i)
		{
			if (x>i)
			{
				check(x-i,L[x-i][y]);
				check(x-i,R[x-i][y]);
			}
			if (x+i<=n)
			{
				check(x+i,L[x+i][y]);
				check(x+i,R[x+i][y]);
			}
		}
		answer(px,py);
	}
	return 0;
}