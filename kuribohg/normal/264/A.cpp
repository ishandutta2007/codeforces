#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int l,r,len,pos[1000010],ans[1000010];
char str[1000010];
int main()
{
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]=='l') pos[i]=len-r,r++;
		else l++,pos[i]=l;
	}
	for(int i=1;i<=len;i++) ans[pos[i-1]]=i;
	for(int i=1;i<=len;i++) printf("%d\n",ans[i]);
	return 0;
}