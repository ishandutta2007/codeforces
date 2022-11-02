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

#define maxn 200010
int n,m,type,x,y,ml,mr,f[maxn],flag[maxn<<2],u,v;
char ch;
#define lc x<<1
#define rc x<<1|1
#define mid (l+r>>1)
int fa(int t)
{
	if (f[t]==t)	return t;
	return f[t]=fa(f[t]);
}
void Union(int x,int y)
{
	if ((u=fa(x))!=(v=fa(y)))	f[u]=v;
}
void merge(int x,int l,int r,int k)
{
	if (ml<=l && mr>=r)
	{
		if (l==r || flag[x])
		{
			Union(l,k);
			return;
		}
		merge(lc,l,mid,k),merge(rc,mid+1,r,k);
		flag[x]=1;
	}
	if (ml<=mid)	merge(lc,l,mid,k);
	if (mr>mid)		merge(rc,mid+1,r,k);
}

int main()
{
	read(n),read(m);
	for (int i=1;i<=n;i++)	f[i]=i;
	while (m--)
	{
		read(type),read(x),read(y);
		if (type==1)	Union(x,y);
		if (type==2 && x!=y)	ml=x+1,mr=y,merge(1,1,n,x);
		if (type==3)	printf(fa(x)==fa(y)?"YES\n":"NO\n");
	}
	return 0;
}