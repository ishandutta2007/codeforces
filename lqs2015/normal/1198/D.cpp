#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,mp[55][55],f[55][55][55][55],val[55][55][55][55],mn[55][55][55],mx[55][55][55],l,r,u,d,l1,r1,l2,r2;
bool e[55][55][55];
char s[55][55];
void upd(int &x,int y)
{
	if (x>y) x=y;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			mp[i][j]=(s[i-1][j-1]=='#');
		}
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			for (int k=0;k<=n;k++)
			{
				mx[i][j][k]=-1e9;mn[i][j][k]=1e9;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=j;k<=n;k++)
			{
				if (mp[k][i])
				{
					mx[i][j][k]=max(mx[i][j][k-1],k);
					mn[i][j][k]=min(mn[i][j][k-1],k);
				}
				else
				{
					mx[i][j][k]=mx[i][j][k-1];
					mn[i][j][k]=mn[i][j][k-1];
				}
				e[i][j][k]=(mx[i][j][k]>0);
			}
		}
	}
	for (int j=1;j<=n;j++)
	{
		for (int k=j;k<=n;k++)
		{
			for (int i=1;i<=n;i++)
			{
				l=1e9;r=-1e9;u=1e9;d=-1e9;
				for (int h=i;h<=n;h++)
				{
					if (e[h][j][k]) 
					{
						if (l>h) l=h;
						if (r<h) r=h;
					}
					if (u>mn[h][j][k]) u=mn[h][j][k];
					if (d<mx[h][j][k]) d=mx[h][j][k];
					val[j][k][i][h]=max(d-u+1,r-l+1);
					if (val[j][k][i][h]<0) val[j][k][i][h]=0;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=j;k<=n;k++)
			{
				f[i][i][j][k]=val[i][i][j][k];
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				f[i][j][k][k]=val[i][j][k][k];
			}
		}
	}
	for (int i=1;i<n;i++)
	{
		for (int j=1;i+j<=n;j++)
		{
			l1=j;r1=i+j;
			for (int k=1;k<n;k++)
			{
				for (int h=1;k+h<=n;h++)
				{
					l2=h;r2=k+h;
					f[l1][r1][l2][r2]=val[l1][r1][l2][r2];
					for (int p=l1;p<r1;p++)
					{
						upd(f[l1][r1][l2][r2],f[l1][p][l2][r2]+f[p+1][r1][l2][r2]);
					}
					for (int p=l2;p<r2;p++)
					{
						upd(f[l1][r1][l2][r2],f[l1][r1][l2][p]+f[l1][r1][p+1][r2]);
					}
				}
			}
		}
	}
	printf("%d\n",f[1][n][1][n]);
	return Accepted;
}