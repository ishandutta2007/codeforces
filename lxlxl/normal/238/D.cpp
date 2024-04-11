#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int ch[10],hn;
void output(int x)
{
	if(x==0) putchar('0');
	while(x) ch[++hn]=x%10,x/=10;
	while(hn) putchar('0'+ch[hn--]);
	putchar(' ');
}

const int maxn = 210000;

int n,m,N;
char str[maxn];
int a[maxn],del[maxn];
int nowi,s[maxn<<3][10];
void push() { nowi++; for(int i=0;i<10;i++) s[nowi][i]=s[nowi-1][i]; }
int f[maxn],g[maxn];

struct List
{
	int fa[maxn];
	int findfa(const int x){ return fa[x]==x?x:fa[x]=findfa(fa[x]); }
}pre,nex;
int t[maxn],tp;

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	while(N<=n) a[++N]=-1;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='>') a[++N]=-1;
		else if(str[i]=='<') a[++N]=-2;
		else a[++N]=str[i]-'0';
	}
	
	for(int i=0;i<=N+1;i++) 
	{
		pre.fa[i]=i,nex.fa[i]=i;
		f[i]=g[i]=-1;
	}
	
	nowi=1; tp=0;
	for(int i=1;i<=n+1;i++) nex.fa[i]=nex.fa[i+1],f[i]=nowi;
	int cnt=0;
	for(int i=n+1,dir=1;i<=N;)
	{
		if(i==n+1+2001)
			int ii=1;
		if(dir==1)
		{
			push();
			int j=nex.findfa(i+1); ++cnt;
			if(f[j]==-1) f[j]=nowi;
			nex.fa[j]=nex.findfa(j+1);
			if(a[j]<0)
			{
				if(!tp) del[i]=1;
				if(a[j]==-2) dir=0,del[j]=1;
				else dir=1;
				tp=0;
			}
			else
			{
				s[nowi][a[j]]++; tp++;
				a[j]--; if(a[j]<0) del[j]=1;
			}
			i=j;
		}
		else
		{
			int mx=-2;
			while(!dir)
			{
				push();
				int j=pre.findfa(i-1); ++cnt;
				if(g[j]==-1) g[j]=nowi;
				if(del[j]) { pre.fa[j]=pre.findfa(j-1); continue; }
				
				if(a[j]<0)
				{
					if(!tp) del[i]=1;
					if(a[j]==-1)
					{
						push();
						if((mx+2)%2==0) dir=1;
						else pre.fa[j]=pre.findfa(j-1);
						while(tp)
						{
							int cc=t[tp--];
							while(cc>=0) s[nowi][cc--]++;
						}
						mx=-2;
					}
				}
				else
				{
					s[nowi][a[j]--]++;
					t[++tp]=a[j]; mx=max(mx,a[j]);
					del[j]=1;
				}
				
				i=j;
			}
		}
	}
	f[N+1]=nowi;
	
	while(m--)
	{
		int l,r; scanf("%d%d",&l,&r);
		l+=n+1,r+=n+1;
		int st=f[l],ed=f[r+1];
		if(g[l-1]!=-1) ed=min(ed,g[l-1]);
		st--;ed--;
		for(int i=0;i<10;i++) output(s[ed][i]-s[st][i]); puts("");
	}
	
	return 0;
}