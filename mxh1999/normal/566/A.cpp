#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 800010
int ans[maxn];
char s[maxn];
int n;
struct Trie
{
	int ch[26];
	int dep;
	int fa;
}	mjy[800010];
struct Mjy
{
	int pos,dep;
}	www[800010];
struct Edge
{
	int v,next;
}	edge[800010];
int g[800010],last[800010],cnt;
int gg[800010],lt[800010];
int tot,now;
ll sum;

int add(int now,int c)
{
	if (mjy[now].ch[c])	return mjy[now].ch[c];
	tot++;
	mjy[now].ch[c]=tot;
	mjy[tot].dep=mjy[now].dep+1;
	mjy[tot].fa=now;
	return tot;
}
void add1(int x,int y)
{
	cnt++;
	edge[cnt].v=y;
	edge[cnt].next=g[x];
	if (g[x]==0)	last[x]=cnt;
	g[x]=cnt;
}
void add2(int x,int y)
{
	cnt++;
	edge[cnt].v=y;
	edge[cnt].next=gg[x];
	if (gg[x]==0)	lt[x]=cnt;
	gg[x]=cnt;
}

bool cmp(Mjy a,Mjy b)
{
	return a.dep>b.dep;
}
int main()
{
	scanf("%d",&n);
	now=1;
	tot=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",&s);
		now=1;
		int l=strlen(s);
		for (int j=0;j<l;j++)
			now=add(now,s[j]-'a');
		add1(now,i);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%s",&s);
		now=1;
		int l=strlen(s);
		for (int j=0;j<l;j++)
			now=add(now,s[j]-'a');
		add2(now,i);
	}
	for (int i=1;i<=tot;i++)
		www[i].pos=i,www[i].dep=mjy[i].dep;
	sort(www+1,www+tot+1,cmp);
	for (int i=1;i<=tot;i++)
	{
		int t=www[i].pos;
		while (g[t]!=0 && gg[t]!=0)
		{
			ans[edge[g[t]].v]=edge[gg[t]].v;
			g[t]=edge[g[t]].next;
			gg[t]=edge[gg[t]].next;
			sum+=www[i].dep;
		}
		int fa=mjy[t].fa;
		if (g[t]!=0)
		{
			if (g[fa]==0)
			{
				g[fa]=g[t];
				last[fa]=last[t];
			}	else
			{
				edge[last[fa]].next=g[t];
				last[fa]=last[t];
			}
		}
		if (gg[t]!=0)
		{
			if (gg[fa]==0)
			{
				gg[fa]=gg[t];
				lt[fa]=lt[t];
			}	else
			{
				edge[lt[fa]].next=gg[t];
				lt[fa]=lt[t];
			}
		}
	}
	printf("%I64d\n",sum);
	for (int i=1;i<=n;i++)
		printf("%d %d\n",i,ans[i]);
	return 0;
}