#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int n;
char s[maxn+5];
int tot=0,t[maxn+5],cnt=0;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1') cnt++;
		else t[++tot]=s[i]-'0';
	}	
	
	int las=tot+1;
	for(int i=1;i<=tot;i++)
	{
		if(t[i]==2)
		{
			las=i;
			break;
		}
	}
	for(int i=1;i<=las-1;i++) printf("%d",t[i]);
	for(int i=1;i<=cnt;i++) printf("1");
	for(int i=las;i<=tot;i++) printf("%d",t[i]);
	printf("\n");
	return 0;
}