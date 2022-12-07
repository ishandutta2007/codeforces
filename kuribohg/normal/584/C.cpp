#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t,a,b,tmin;
char s1[100010],s2[100010],ans[100010];
int main()
{
	scanf("%d%d",&n,&t);
	scanf("%s%s",s1,s2);
	for(int i=0;i<n;i++)
		if(s1[i]==s2[i]) a++;
		else b++;
	tmin=b/2;
	if(b%2) tmin++;
	if(t<tmin) {puts("-1");return 0;}
	t-=tmin;
	int pre=0;
	for(int i=0;i<n;i++)
		if(s1[i]!=s2[i])
		{
			if(b==1&&pre==0)
			{
				ans[i]='a';
				while(ans[i]==s1[i]||ans[i]==s2[i])
					ans[i]++;
				b--;
			}
			else
			{
				if(pre) ans[i]=s1[i];
				else ans[i]=s2[i];
				pre^=1;
				b--;
			}
		}
	for(int i=0;i<n;i++)
		if(s1[i]==s2[i])
		{
			if(t)
			{
				t--;
				ans[i]='a';
				while(ans[i]==s1[i]) ans[i]++;
			}
			else ans[i]=s1[i];
		}
	t*=2;
	for(int i=0;i<n;i++)
		if(s1[i]!=s2[i])
		{
			if(t)
			{
				t--;
				ans[i]='a';
				while(ans[i]==s1[i]||ans[i]==s2[i]) ans[i]++;
			}
		}
	puts(ans);
	return 0;
}