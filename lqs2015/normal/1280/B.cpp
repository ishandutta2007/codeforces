#include<bits/stdc++.h>
using namespace std;
int test,n,m;
char s[111][111];
bool f;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		f=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='A') f=1;
			}
		}
		if (!f) 
		{
			printf("MORTAL\n");
			continue;
		}
		f=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='A' && (i==0 || i==n-1 || j==0 || j==m-1)) f=1;
			}
		}
		if (!f)
		{
			printf("4\n");
			continue;
		}
		f=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='P') f=1;
			}
		}
		if (!f)
		{
			printf("0\n");
			continue;
		}
		f=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='P' && i==0) f=1;
			}
		}
		if (!f)
		{
			printf("1\n");
			continue;
		}
		f=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='P' && i==n-1) f=1;
			}
		}
		if (!f)
		{
			printf("1\n");
			continue;
		}
		f=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='P' && j==0) f=1;
			}
		}
		if (!f)
		{
			printf("1\n");
			continue;
		}
		f=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='P' && j==m-1) f=1;
			}
		}
		if (!f)
		{
			printf("1\n");
			continue;
		}
		f=0;
		for (int i=0;i<n;i++)
		{
			bool flag=0;
			for (int j=0;j<m;j++)
			{
				if (s[i][j]=='P') flag=1;
			}
			if (!flag) f=1;
		}
		if (f) 
		{
			printf("2\n");
			continue;
		}
		f=0;
		for (int j=0;j<m;j++)
		{
			bool flag=0;
			for (int i=0;i<n;i++)
			{
				if (s[i][j]=='P') flag=1;
			}
			if (!flag) f=1;
		}
		if (f)
		{
			printf("2\n");
			continue;
		}	
		if (s[0][0]=='P' && s[0][m-1]=='P' && s[n-1][0]=='P' && s[n-1][m-1]=='P') printf("3\n");
		else printf("2\n");
	}
	return 0;
}