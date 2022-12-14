#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
int n,m,sz,hashh,ans,has;
char s[111];
map<pair<int,int>,int> mp;
map<pair<int,int>,bool> used;
void dfs(int i,int hashh,int has)
{
	if (i==sz)
	{
		if (used.find(make_pair(hashh,has))==used.end()) ans+=mp[make_pair(hashh,has)];
		used[make_pair(hashh,has)]=1;
		return;
	}
	if (s[i]=='?')
	{
		dfs(i+1,hashh,has);
		for (int j=1;j<=5;j++) dfs(i+1,hashh*11+j,has*13+j);
	}
	else dfs(i+1,hashh*11+(s[i]-'a'+1),has*13+(s[i]-'a'+1));
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		sz=strlen(s);
		hashh=0;has=0;
		for (int j=0;j<sz;j++)
		{
			hashh=hashh*11+(s[j]-'a'+1);
			has=has*13+(s[j]-'a'+1);
		}
		mp[make_pair(hashh,has)]++;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%s",s);
		ans=0;
		sz=strlen(s);
		used.clear();
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}