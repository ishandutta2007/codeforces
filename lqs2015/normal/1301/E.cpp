#include<bits/stdc++.h>
using namespace std;
const int magic=30;
int n,m,q,val[555][555],mx[500][500][500],sum[4][555][555],l,r,mid,x,y,xx,yy,buc[18][500][500],all;
char s[555][555],ch[]={'R','G','Y','B'};
bool check1(int x,int y)
{
	if (!mid) return 1;
	if (x<mid || y<mid) return 0;
	if (sum[0][x][y]-sum[0][x-mid][y]-sum[0][x][y-mid]+sum[0][x-mid][y-mid]!=mid*mid) return 0;
	if (x<mid || y+mid>m) return 0;
	if (sum[1][x][y+mid]-sum[1][x-mid][y+mid]-sum[1][x][y]+sum[1][x-mid][y]!=mid*mid) return 0;
	if (x+mid>n || y<mid) return 0;
	if (sum[2][x+mid][y]-sum[2][x][y]-sum[2][x+mid][y-mid]+sum[2][x][y-mid]!=mid*mid) return 0;
	if (x+mid>n || y+mid>m) return 0;
	if (sum[3][x+mid][y+mid]-sum[3][x+mid][y]-sum[3][x][y+mid]+sum[3][x][y]!=mid*mid) return 0;
	return 1;
}
int getmx(int x,int y,int xx,int yy)
{
	if (x>y || xx>yy) return 0;
	int lb=(x-1)/magic,rb=(y-1)/magic,res=0,cc;
	if (lb==rb)
	{
		for (int i=x;i<=y;i++) 
		{
			res=max(res,mx[i][xx][yy]);
		}
	}
	else
	{
		cc=(lb+1)*magic;
		for (int i=x;i<=cc;i++) res=max(res,mx[i][xx][yy]);
		cc=rb*magic+1;
		for (int i=cc;i<=y;i++) res=max(res,mx[i][xx][yy]);
		for (int i=lb+1;i<rb;i++) res=max(res,buc[i][xx][yy]);
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for (int i=0;i<4;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=m;k++)
			{
				sum[i][j][k]=sum[i][j][k-1]+sum[i][j-1][k]-sum[i][j-1][k-1];
				if (s[j-1][k-1]==ch[i]) sum[i][j][k]++;
			}
		}
	}
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<m;j++)
		{
			l=0;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (check1(i,j)) l=mid+1;
				else r=mid-1;
			}
			val[i][j]=r;
		}
	}
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<m;j++)
		{
			mx[i][j][j]=val[i][j];
			for (int k=j+1;k<m;k++)
			{
				mx[i][j][k]=max(mx[i][j][k-1],val[i][k]);
			}
		}
	}
	all=(n-1+magic-1)/magic;
	for (int i=0;i<all;i++)
	{
		for (int j=i*magic+1;j<=min(n-1,(i+1)*magic);j++)
		{
			for (int k=1;k<m;k++)
			{
				for (int h=k;h<m;h++)
				{
					buc[i][k][h]=max(buc[i][k][h],mx[j][k][h]);
				}
			}
		}
	}
	while(q--)
	{
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		l=0;r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (getmx(x+mid-1,xx-mid,y+mid-1,yy-mid)>=mid) l=mid+1;
			else r=mid-1; 
		}
		printf("%d\n",4*r*r);
	}
	return 0;
}