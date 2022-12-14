#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[11111],res[11111];
int cnt,sz,pnt,knt;
bool used[31];
bool iscon(char c)
{
	return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
}
int main()
{
	scanf("%s",s);
	sz=strlen(s);
	for (int i=0;i<sz;i++)
	{
		res[cnt++]=s[i];
		if (iscon(s[i]))
		{
			pnt++;
			if (!used[s[i]-'a'])
			{
				used[s[i]-'a']=1;
				knt++;
			}
			if (pnt>=3 && knt>1)
			{
				res[cnt-1]='\0';
				printf("%s ",res);
				memset(used,0,sizeof(used));
				cnt=1;res[0]=s[i];
				used[s[i]-'a']=1;
				knt=pnt=1;
			}
		}
		else 
		{
			memset(used,0,sizeof(used));
			knt=pnt=0;
		}
	}
	if (cnt)
	{
		res[cnt]='\0';
		printf("%s\n",res);
	}
	return 0;
}