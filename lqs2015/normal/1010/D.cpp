#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,tp[1111111],l[1111111],r[1111111],x,y;
char s[11];
int val[1111111];
bool ans[1111111],tag[1111111];
void Init(int i)
{
	if (l[i]) Init(l[i]);
	if (r[i]) Init(r[i]);
	if (tp[i]==1) return;
	if (tp[i]==2) val[i]=!val[l[i]];
	else if (tp[i]==3) val[i]=val[l[i]]&val[r[i]];
	else if (tp[i]==4) val[i]=val[l[i]]|val[r[i]];
	else val[i]=val[l[i]]^val[r[i]];
}
void dfs1(int i)
{
	if (tp[i]==1) return;
	if (tp[i]==2) dfs1(l[i]);
	else if (tp[i]==3)
	{
		if (val[i])
		{
			dfs1(l[i]);
			dfs1(r[i]);
		}
		else
		{
			if (!val[l[i]]) tag[r[i]]=1;
			if (!val[r[i]]) tag[l[i]]=1;
			if (!tag[r[i]]) dfs1(r[i]);
			if (!tag[l[i]]) dfs1(l[i]);
		}
	}
	else if (tp[i]==4)
	{
		if (!val[i])
		{
			dfs1(l[i]);
			dfs1(r[i]);
		}
		else
		{
			if (val[l[i]] && val[r[i]])
			{
				tag[l[i]]=tag[r[i]]=1;
				return;
			}
			if (val[l[i]])
			{
				tag[r[i]]=1;
				dfs1(l[i]);
			}
			else
			{
				tag[l[i]]=1;
				dfs1(r[i]);
			}
 		}
	}
	else
	{
		dfs1(l[i]);
		dfs1(r[i]);
	}
}
void dfs2(int i)
{
	if (tp[i]==1) 
	{
		tag[i]=1;
		return;
	}
	if (tp[i]==2) dfs2(l[i]);
	else if (tp[i]==3)
	{
		if (val[i])
		{
			dfs2(l[i]);
			dfs2(r[i]);
		}
		else
		{
			if (!val[l[i]] && !val[r[i]]) return;
			if (!val[l[i]]) dfs2(l[i]);
			else dfs2(r[i]);
		}
	}
	else if (tp[i]==4)
	{
		if (!val[i])
		{
			dfs2(l[i]);
			dfs2(r[i]);
		}
		else
		{
			if (val[l[i]] && val[r[i]]) return;
			if (val[r[i]]) dfs2(r[i]);
			else dfs2(l[i]);
 		}
	}
	else
	{
		dfs2(l[i]);
		dfs2(r[i]);
	}
}
void dfs(int i,int f,bool fl)
{
	if (tp[i]==1)
	{
		if (fl || tag[i]) ans[i]=f;
		return;
	}
	if (tp[i]==2) dfs(l[i],f,fl|tag[i]);
	else 
	{
		dfs(l[i],f,fl|tag[i]);
		dfs(r[i],f,fl|tag[i]);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		if (s[0]=='I') 
		{
			scanf("%d",&x);
			tp[i]=1;
			val[i]=x;
		}
		else if (s[0]=='N')
		{
			scanf("%d",&x);
			tp[i]=2;
			l[i]=x;
		}
		else
		{
			scanf("%d%d",&x,&y);
			if (s[0]=='A') 
			{
				tp[i]=3;
				l[i]=x;r[i]=y;
			}
			else if (s[0]=='O')
			{
				tp[i]=4;
				l[i]=x;r[i]=y;
			}
			else
			{
				tp[i]=5;
				l[i]=x;r[i]=y;
			}
		}
	}
	Init(1);
	dfs1(1);
	dfs(1,val[1],0);
	memset(tag,0,sizeof(tag));
	dfs2(1);
	dfs(1,!val[1],0);
	for (int i=1;i<=n;i++)
	{
		if (tp[i]==1) printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}