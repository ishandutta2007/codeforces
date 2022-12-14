#include<bits/stdc++.h>
using namespace std;
int n,test,p1,p2,pre1,pre2,ans[333333];
char s[333333];
bool flag,can;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		can=0;
		for (int i=0;i<=9;i++)
		{
			p1=-1;p2=n+1;
			for (int j=0;j<n;j++)
			{
				if (s[j]-'0'<i) p1=j;
				if (s[j]-'0'>i && p2==n+1) p2=j; 
			}
			flag=0;
			for (int j=0;j<n;j++)
			{
				if (s[j]-'0'==i && j>p2 && j<p1) flag=1;
			}
			if (flag) continue;
			pre1=pre2=-1;
			for (int j=0;j<n;j++)
			{
				if (s[j]-'0'<i) 
				{
					if (s[j]-'0'<pre1) flag=1;
					pre1=s[j]-'0';
				}
				else if (s[j]-'0'>i)
				{
					if (s[j]-'0'<pre2) flag=1;
					pre2=s[j]-'0';
				}
			}
			if (flag) continue;
			for (int j=0;j<n;j++)
			{
				if (s[j]-'0'<i) ans[j]=1;
				else if (s[j]-'0'>i) ans[j]=2;
				else if (j<p2) ans[j]=2;
				else ans[j]=1;
			}
			can=1;
			for (int j=0;j<n;j++) printf("%d",ans[j]);
			printf("\n");
			break;
		}
		if (!can) printf("-\n");
	}
	return 0;
}