#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int T,n;
char s[maxn+5];
int main()
{
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1') tot++;
		}
		if(tot==0)
		{
			printf("0\n");
			continue;
		}
		int L=-1,R=-1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				L=i;
				break;
			}
		}
		for(int i=n;i>=1;i--)
		{
			if(s[i]=='1')
			{
				R=i;
				break;
			}
		}
		tot=0;
		for(int i=L;i<=R;i++)
		{
			if(s[i]=='0') tot++;
		}
		printf("%d\n",tot);
	}
	return 0;
}