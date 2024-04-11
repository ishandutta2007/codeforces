#include<bits/stdc++.h>
using namespace std;

const int maxn=5010;
char s[maxn];
int n,ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
	{
		int num=0,cnt=0;
		for (int j=i;j<=n;j++)
		{
			if (s[j]=='(')	num++;
			if (s[j]==')')
			{
				num--;
				if (num<0)
				{
					cnt--;
					num+=2;
					if (cnt<0)	break;
				}
			}
			if (s[j]=='?')
			{
				num--;
				cnt++;
				if (num<0)
				{
					cnt--;
					num+=2;
				}
			}
			if (num==0)	ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}