#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,q,cnt[1111],l,r,rb,ans;
char s[1111],t[1111];
bool f;
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s",s,t);
	for (int i=0;i<n-m+1;i++)
	{
		f=0;
		for (int j=i;j<i+m;j++)
		{
			if (s[j]!=t[j-i]) 
			{
				f=1;
				break;
			}
		}
		if (!f) cnt[i]++;
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		l--;r--;
		rb=r-m+1;ans=0;
		for (int i=l;i<=rb;i++)
		{
			ans+=cnt[i];
		} 
		printf("%d\n",ans);
	}
	return 0;
}