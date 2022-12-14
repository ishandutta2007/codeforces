#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1111111],t[1111111];
int cnt,snum[33],tnum[33],ls,lt,ynum[33],totnum[33],pos;
int main()
{
	scanf("%s%s",s,t);
	ls=strlen(s);
	lt=strlen(t);
	for (int i=0;i<ls;i++)
	{
		if (s[i]=='?') cnt++;
		else snum[s[i]-'a']++;
	}
	for (int i=0;i<lt;i++)
	{
		tnum[t[i]-'a']++;
	}
	while(cnt>0)
	{
		memset(ynum,0,sizeof(ynum));
		for (int i=0;i<26;i++)
		{
			if (!tnum[i]) continue;
			if (snum[i]>=tnum[i]) snum[i]-=tnum[i];
			else
			{
				ynum[i]=tnum[i]-snum[i];
				cnt-=(tnum[i]-snum[i]);
				snum[i]=0;
			}
		}
		if (cnt<0) break;
		for (int i=0;i<26;i++) totnum[i]+=ynum[i];
	}
	for (int i=0;i<ls;i++)
	{
		if (s[i]=='?')
		{
			while(pos<26 && totnum[pos]==0) pos++;
			if (pos>=26) printf("a");
			else 
			{
				printf("%c",(char)(pos+'a'));
				totnum[pos]--;
			}
		}
		else printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}