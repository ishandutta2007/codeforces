#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,ind[MAXN],ans[MAXN],top,q[MAXN],l,r;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int trans[MAXN];
char str[110][110];
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",str[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<strlen(str[i]);j++)
			str[i][j]=str[i][j]-'a'+1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<min(strlen(str[i]),strlen(str[i+1]));j++)
		{
			if(str[i][j]==str[i+1][j]) continue;
			else
			{
				adde(str[i][j],str[i+1][j]);
				ind[str[i+1][j]]++;
				break;
			}
		}
	}
	l=1;
	for(int i=1;i<=26;i++)
		if(ind[i]==0) q[++r]=i;
	while(l<=r)
	{
		int x=q[l++];
		ans[++top]=x;
		for(int i=head[x];i;i=next[i])
		{
			ind[to[i]]--;
			if(ind[to[i]]==0) q[++r]=to[i];
		}
	}
	for(int i=1;i<=26;i++) trans[ans[i]]=i;
	for(int i=1;i<=n;i++)
		for(int j=0;j<strlen(str[i]);j++)
			str[i][j]=trans[str[i][j]];
	if(top!=26) {puts("Impossible");return 0;}
	else
	{
		for(int i=1;i<n;i++)
			if(strcmp(str[i],str[i+1])>0) {puts("Impossible");return 0;}
	}
	for(int i=1;i<=26;i++)
		putchar(ans[i]+'a'-1);
	puts("");
	return 0;
}