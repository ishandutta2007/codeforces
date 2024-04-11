#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,rw[333333][4][4],col[333333][4][4],a,b,c,d,mn,cur;
bool tp;
pair<int,int> ans[333333];
vector<int> aa[333333];
char s[333333];
void Out(int a)
{
	if (a==1) printf("A");
	else if (a==2) printf("C");
	else if (a==3) printf("G");
	else printf("T");
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) aa[i].resize(m+1);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=m;j++)
		{
			if (s[j-1]=='A') aa[i][j]=1;
			else if (s[j-1]=='C') aa[i][j]=2;
			else if (s[j-1]=='G') aa[i][j]=3;
			else aa[i][j]=4;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=4;j++)
		{
			for (int k=1;k<=4;k++)
			{
				if (j==k) continue;
				for (int h=1;h<=m;h++)
				{
					if (h&1) rw[i][j][k]+=(aa[i][h]!=j);
					else rw[i][j][k]+=(aa[i][h]!=k);
				}
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=4;j++)
		{
			for (int k=1;k<=4;k++)
			{
				if (j==k) continue;
				for (int h=1;h<=n;h++)
				{
					if (h&1) col[i][j][k]+=(aa[h][i]!=j);
					else col[i][j][k]+=(aa[h][i]!=k);
				}
			}
		}
	}
	mn=1e9;
	for (a=1;a<=4;a++)
	{
		for (b=1;b<=4;b++)
		{
			for (c=1;c<=4;c++)
			{
				for (d=1;d<=4;d++)
				{
					if (a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
					{
						cur=0;
						for (int i=1;i<=n;i++)
						{
							if (i&1) cur+=min(rw[i][a][b],rw[i][b][a]);
							else cur+=min(rw[i][c][d],rw[i][d][c]);
						}
						if (cur<mn)
						{
							mn=cur;tp=0;
							for (int i=1;i<=n;i++)
							{
								if (i&1)
								{
									if (rw[i][a][b]<rw[i][b][a]) ans[i]=make_pair(a,b);
									else ans[i]=make_pair(b,a);
								}
								else
								{
									if (rw[i][c][d]<rw[i][d][c]) ans[i]=make_pair(c,d);
									else ans[i]=make_pair(d,c);
								}
							}
						}
					}
				}
			}
		}
	}
	for (a=1;a<=4;a++)
	{
		for (b=1;b<=4;b++)
		{
			for (c=1;c<=4;c++)
			{
				for (d=1;d<=4;d++)
				{
					if (a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
					{
						cur=0;
						for (int i=1;i<=m;i++)
						{
							if (i&1) cur+=min(col[i][a][b],col[i][b][a]);
							else cur+=min(col[i][c][d],col[i][d][c]);
						}
						if (cur<mn)
						{
							mn=cur;tp=1;
							for (int i=1;i<=m;i++)
							{
								if (i&1)
								{
									if (col[i][a][b]<col[i][b][a]) ans[i]=make_pair(a,b);
									else ans[i]=make_pair(b,a);
								}
								else
								{
									if (col[i][c][d]<col[i][d][c]) ans[i]=make_pair(c,d);
									else ans[i]=make_pair(d,c);
								}
							}
						}
					}
				}
			}
		}
	}
	if (!tp)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if (j&1) Out(ans[i].first);
				else Out(ans[i].second);
			}
			printf("\n");
		}
	} 
	else
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if (i&1) Out(ans[j].first);
				else Out(ans[j].second);
			}
			printf("\n");
		}
	}
	return Accepted;
}