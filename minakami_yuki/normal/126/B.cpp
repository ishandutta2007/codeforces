#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=1e6+10;
int n;
char s[N];
int nxt[N];

int main()
{
	int j=0,mx=0;
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=2;i<=n;++i)
	{
		while(s[i]!=s[j+1]&&j>0) j=nxt[j];
		if(s[i]==s[j+1]) j=j+1;
		nxt[i]=j;
	}
	for(int i=2;i<n;++i) mx=max(mx,nxt[i]);
	j=nxt[n];
	while(j>mx) j=nxt[j];
	if(j>0)
	{
		for(int i=1;i<=j;++i) putchar(s[i]);puts("");
	}
	else printf("Just a legend\n");
	return 0;
}