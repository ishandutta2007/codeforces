//mjy.. good luck ..
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;
typedef pair<int,int>	PII;

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

#define maxn 1000010
#define maxm 26
struct SAM
{
	int len,fa,num;
	int trans[maxm];
	int vis;
}	a[maxn<<1];
int now,tot,root;
char s[maxn],t[maxn];
int n,m;

int add(int u,int c)
{
	int p=u;
	int np=++tot;
	a[np].len=a[p].len+1,a[np].num=1;
	while (a[p].trans[c]==0 && p)	a[p].trans[c]=np,p=a[p].fa;
	if (!p)	a[np].fa=root;else
	{
		int q=a[p].trans[c];
		if (a[q].len==a[p].len+1)	a[np].fa=q;else
		{
			int nq=++tot;
			a[nq].len=a[p].len+1;
			a[nq].fa=a[q].fa;
			memcpy(a[nq].trans,a[q].trans,sizeof(a[q].trans));
			a[np].fa=a[q].fa=nq;
			while (a[p].trans[c]==q)	a[p].trans[c]=nq,p=a[p].fa;
		}
	}
	return np;
}
PII p[maxn<<1];
bool cmp(PII a,PII b)
{
	return a.fi>b.fi;
}
void pre()
{
	for (int i=1;i<=tot;i++)	p[i].fi=a[i].len,p[i].se=i;
	sort(p+1,p+tot+1,cmp);
	for (int i=1;i<=tot;i++)
	if (p[i].se!=root)	a[a[p[i].se].fa].num+=a[p[i].se].num;
}
void solve(int nowtime)
{
	int mjy=0;
	n=strlen(t+1);
	for (int i=1;i<=n;i++)	t[n+i]=t[i];
	int now=1,l=0;
	for (int i=1;i<=2*n;i++)
	{
		while (!a[now].trans[t[i]-'a'] && now!=root)	now=a[now].fa,l=a[now].len;
		now=a[now].trans[t[i]-'a'],l++;
		if (now==0)	now=1,l=0;
		while (l>n && a[a[now].fa].len>=n)	now=a[now].fa,l=a[now].len;
		if (l>=n && a[now].vis!=nowtime)
		{
			a[now].vis=nowtime;
			mjy+=a[now].num;
		}
	}
	printf("%d\n",mjy);
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	now=tot=root=1;
	for (int i=1;i<=n;i++)	now=add(now,s[i]-'a');
	pre();
	read(m);
	for (int i=1;i<=m;i++)
	{
		scanf("%s",t+1);
		solve(i);
	}
	return 0;
}