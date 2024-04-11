#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[111111];
int m,l,r,n,pos[111111],nxt[111111][28],pre[111111][28],pr[111111][28],nx[111111][28],cur[28],a[111111];
int prefix[111111];
int solve(int l,int r);
int getsuf(int pos,int k)
{
	if (~nx[pos][k]) return nx[pos][k];
	return nx[pos][k]=solve(pos,nxt[pos][k]-1);
}
int getpre(int pos,int k)
{
	if (~pr[pos][k]) return pr[pos][k];
	return pr[pos][k]=solve(pre[pos][k]+1,pos);
}
int solve(int l,int r)
{
	if (l>r) return 0;
	if (l==r) return 1;
	bool used[55];
	memset(used,0,sizeof(used));
	int ans,res;
	for (int i=0;i<26;i++)
	{
		int s=nxt[l][i],e=pre[r][i];
		if (s>e || !s || !e) continue;
		ans=prefix[e]^prefix[pre[s][i]];
		if (s!=l) ans^=getsuf(l,i);
		if (e!=r) ans^=getpre(r,i);
		used[ans]=1;
	}
	res=0;
	while(used[res]) res++;
	return res;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	memset(nx,-1,sizeof(nx));
	memset(pr,-1,sizeof(pr));
	for (int i=n;i>=1;i--)
	{
		cur[a[i]]=i;
		for (int j=0;j<26;j++) nxt[i][j]=cur[j];
	}
	memset(cur,0,sizeof(cur));
	for (int i=1;i<=n;i++)
	{
		cur[a[i]]=i;
		for (int j=0;j<26;j++) pre[i][j]=cur[j];
	}
	for (int i=1;i<=n;i++)
	{
		if (!pre[i][a[i]]) continue;
		prefix[i]=prefix[pre[i-1][a[i]]]^solve(pre[i-1][a[i]]+1,i-1);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		if (!solve(l,r)) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}