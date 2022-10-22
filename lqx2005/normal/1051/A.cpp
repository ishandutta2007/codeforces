#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
int t,n;
char s[maxn+5];
int cnt[3];
char a[3]={'a','1','A'};
int main()
{
	scanf("%d",&t);
	for(int tot=1;tot<=t;tot++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]>='a'&&s[i]<='z') cnt[0]++;
			else if(s[i]>='0'&&s[i]<='9') cnt[1]++;
			else cnt[2]++;
		}
		for(int i=1;i<=n;i++)
		{
			int type=0;
			if(s[i]>='a'&&s[i]<='z') type=0;
			else if(s[i]>='0'&&s[i]<='9') type=1;
			else type=2;		
			for(int j=0;j<=2;j++)
			{
				if(j==type) continue;
				if(cnt[type]>=2&&cnt[j]==0)
				{
					cnt[type]--;
					cnt[j]++;
					s[i]=a[j];
					break;
				}
			}
		}
		printf("%s\n",s+1);
	}
	return 0;
}