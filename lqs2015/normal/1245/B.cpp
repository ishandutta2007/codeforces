#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,win;
char s[111],ans[111];
bool fuck[111];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s);
		win=0;memset(fuck,0,sizeof(fuck));
		for (int i=0;i<n;i++)
		{
			if (s[i]=='R')
			{
				if (b) 
				{
					b--;
					win++;
					ans[i]='P';
				}
				else fuck[i]=1;
			}
			else if (s[i]=='P')
			{
				if (c)
				{
					c--;
					win++;
					ans[i]='S';
				}
				else
				{
					fuck[i]=1;
				}
			}
			else
			{
				if (a)
				{
					a--;
					win++;
					ans[i]='R';
				}
				else fuck[i]=1;
			}
		}
		if (win>=(n+1)/2)
		{
			printf("YES\n");
			for (int i=0;i<n;i++)
			{
				if (fuck[i])
				{
					if (a)
					{
						ans[i]='R';
						a--;
					}
					else if (b) 
					{
						ans[i]='P';
						b--;
					}
					else
					{
						ans[i]='S';
						c--;
					}
				}
			}
			ans[n]='\0';
			printf("%s\n",ans);
		}
		else printf("NO\n");
	}
	return 0;
}