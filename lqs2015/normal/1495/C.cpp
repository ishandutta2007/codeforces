#include<bits/stdc++.h>
using namespace std;
int test,n,m,flg;
char s[555][555];
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
		if (m%3==0)
		{
			for (int i=1;i<m;i+=3)
			{
				for (int j=0;j<n;j++)
				s[j][i]='X';
			}
			for (int i=1;i+3<m;i+=3)
			{
				flg=0;
				for (int j=0;j<n;j++)
				{
					if (s[j][i+1]=='X')
					{
						s[j][i+2]='X';
						flg=1;
						break;
					}
					if (s[j][i+2]=='X')
					{
						s[j][i+1]='X';
						flg=1;
						break;
					}
				}
				if (!flg)
				{
					s[0][i+1]=s[0][i+2]='X';
				}
			}
		}
		else
		{
			for (int i=0;i<m;i+=3)
			{
				for (int j=0;j<n;j++)
				s[j][i]='X';
			}
			for (int i=0;i+3<m;i+=3)
			{
				flg=0;
				for (int j=0;j<n;j++)
				{
					if (s[j][i+1]=='X')
					{
						s[j][i+2]='X';
						flg=1;
						break;
					}
					if (s[j][i+2]=='X')
					{
						s[j][i+1]='X';
						flg=1;
						break;
					}
				}
				if (!flg)
				{
					s[0][i+1]=s[0][i+2]='X';
				}
			}
		}
		for (int i=0;i<n;i++)
		{
			printf("%s\n",s[i]);
		}
	}
	return 0;
}