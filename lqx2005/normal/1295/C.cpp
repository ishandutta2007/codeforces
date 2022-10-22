#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
int T,n,m;
char s[maxn+5],t[maxn+5];
int ch[maxn+5][26];
int main()
{
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		memset(ch,0,sizeof(ch));
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1),m=strlen(t+1);
		for(int i=1;i<=n;i++) s[i+n]=s[i];
		for(int i=0;i<=25;i++) ch[2*n][i]=-1;
		ch[2*n][s[2*n]-'a']=2*n;
		for(int k=2*n-1;k>=1;k--)
		{
			for(int i=0;i<26;i++) ch[k][i]=ch[k+1][i];
			ch[k][s[k]-'a']=k;
		}
		int now=1;
		int fag=0,ans=1;
		for(int i=1;i<=m;i++)
		{
			if(now>n) now-=n,ans++;
			if(ch[now][t[i]-'a']==-1) 
			{
				fag=1;
				break;
			}
			now=ch[now][t[i]-'a'];
			if(now>n) now-=n,ans++;
			now++;
		}
		if(fag) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}