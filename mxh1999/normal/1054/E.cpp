#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
struct Ans
{
	int x1,y1,x2,y2;
}	ans[maxn<<2];
string s[310][310];
#ifdef LOCAL
string ha[310][310];
#endif
int n,m;
int nnm;
int l[310][310];

#ifdef LOCAL
void debug()
{

	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			printf("%s ",ha[i][j].c_str());
		printf("\n");
	}
}
#endif
void yd(int x1,int y1,int x2,int y2)
{
	nnm++;
	ans[nnm].x1=x1;
	ans[nnm].y1=y1;
	ans[nnm].x2=x2;
	ans[nnm].y2=y2;
#ifdef LOCAL
	ha[x2][y2]=ha[x1][y1].back()+ha[x2][y2];
	ha[x1][y1].pop_back();
#endif
}
void move0(int x,int y)
{
	if (x==n)
	{
		yd(x,y,n,m-1);
		return;
	}
	if (y==m)
	{
		yd(x,y,x,m-1);
		yd(x,y-1,n,m-1);
	}	else
	{
		yd(x,y,n,y);
		l[n][y]++;
	}
}
void move1(int x,int y)
{
	if (x==n)
	{
		yd(x,y,n,m);
		return;
	}
	if (y==m)
	{
		yd(x,y,n,m);
	}	else
	{
		yd(x,y,x,m);
		l[x][m]++;
	}
}
void prepare()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (i==n && j>=m-1)	break;
			for (int k=s[i][j].size()-1;k>=0;k--)
				if (s[i][j][k]=='0')	move0(i,j);else move1(i,j);
			for (int _=1;_<=l[i][j];_++)
			{
				if (i==n)	yd(i,j,n,m-1);else	yd(i,j,n,m);
			}
		}
#ifdef LOCAL
	debug();
#endif
	for (int k=s[n][m-1].size()-1;k>=0;k--)
		if (s[n][m-1][k]=='0')
		{
			yd(n,m-1,1,m-1);
			yd(1,m-1,n,m-1);
		}	else	yd(n,m-1,n,m);
#ifdef LOCAL
	debug();
#endif
	for (int k=s[n][m].size()-1;k>=0;k--)
		if (s[n][m][k]=='1')
		{
			yd(n,m,1,m);
			yd(1,m,n,m);
		}	else	yd(n,m,n,m-1);
}
void doit()
{
	for (int k=s[n][m-1].size()-1;k>=0;k--)
		if (s[n][m-1][k]=='0')
		{
			yd(n,m-1,1,m-1);
			yd(1,m-1,n,m-1);
		}	else
		{
			yd(n,m,n,m-1);
		}
	for (int k=s[n][m].size()-1;k>=0;k--)
		if (s[n][m][k]=='1')
		{
			yd(n,m,1,m);
			yd(1,m,n,m);
		}	else
			yd(n,m-1,n,m);
	for (int i=1;i<n;i++)
		for (int k=s[i][m].size()-1;k>=0;k--)
			if (s[i][m][k]=='0')	yd(n,m-1,i,m-1);
	for (int i=1;i<n;i++)
		for (int k=s[i][m-1].size()-1;k>=0;k--)
			if (s[i][m-1][k]=='0')	yd(n,m-1,i,m-1);else
			{
				yd(n,m,i,m);
				yd(i,m,i,m-1);
			}
	for (int i=1;i<n;i++)
		for (int k=s[i][m].size()-1;k>=0;k--)
			if (s[i][m][k]=='0')	yd(i,m-1,i,m);else	yd(n,m,i,m);
	for (int i=1;i<n;i++)
		for (int j=1;j<m-1;j++)
			for (int k=s[i][j].size()-1;k>=0;k--)
				if (s[i][j][k]=='0')	yd(n,m-1,n,j),yd(n,j,i,j);else yd(n,m,n,j),yd(n,j,i,j);
	for (int j=1;j<m-1;j++)
			for (int k=s[n][j].size()-1;k>=0;k--)
				if (s[n][j][k]=='0')	yd(n,m-1,n,j);else yd(n,m,n,j);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>s[i][j];
#ifdef LOCAL
			ha[i][j]=s[i][j];
#endif
			l[i][j]=0;
		}
	prepare();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>s[i][j];
		}
#ifdef LOCAL
	debug();
#endif
	doit();
#ifdef LOCAL
	debug();
#endif
	printf("%d\n",nnm);
	for (int i=1;i<=nnm;i++)
		printf("%d %d %d %d\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2);
	return 0;
}