#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
char s[100005];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		if(strlen(s+1)>10)
		printf("%c%d%c\n",s[1],strlen(s+1)-2,s[strlen(s+1)]);
		else printf("%s\n",s+1);
	}
}