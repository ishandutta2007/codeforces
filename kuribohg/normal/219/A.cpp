#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int k,len,a[31];
char str[2010],newstr[2010],tot;
int main()
{
	scanf("%d%s",&k,str);
	len=strlen(str);
	if(len%k!=0) {puts("-1");return 0;}
	else
	{
		for(int i=0;i<len;i++) a[str[i]-'a']++;
		for(int i=0;i<26;i++)
		{
			if(a[i]%k!=0) {puts("-1");return 0;}
			a[i]/=k;
		}
		for(int i=0;i<26;i++)
			for(int j=1;j<=a[i];j++)
				newstr[tot++]=i+'a';
		for(int i=1;i<=k;i++) printf("%s",newstr);
		puts("");
	}
	return 0;
}