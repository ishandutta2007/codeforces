//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 400005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int W[N],fa[N],s[N][2],pw2[N],bel[N],ans,n1,n2,m,q,id;
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
void ed(int &x,int y)
{
	x=(x-y+mod)%mod;
}
int gf(int k)
{
	if (!fa[k]) return k;
	if (!fa[fa[k]]) return fa[k];
	int f=fa[k];
	fa[k]=gf(f);
	W[k]=W[k]^W[f];
	return fa[k];
}
int getw(int k)
{
	int f=gf(k);
	if (f==k) return W[k];
	return W[k]^W[f];
}
void merge(int x,int y)
{
//	swap(x,y);
	x=gf(x),y=gf(y);
	if (x==y) return;
	ed(ans,s[x][W[x]]);
	ed(ans,s[y][W[y]]);
	ad(s[y][W[y]],s[x][W[x]]);
	ad(s[y][W[y]^1],s[x][W[x]^1]);
	fa[x]=y;
	W[x]^=W[y];
	ad(ans,s[y][W[y]]);
}
void ins(int x,int y)
{
	++id;
	s[id][0]=pw2[id];W[id]=0,fa[id]=0;ad(ans,s[id][0]);
	if (!bel[x]&&!bel[y]) bel[x]=id,bel[y]=id;
	else
	{
		if (!bel[x]) swap(x,y);
		if (!bel[y])
		{
			int w=getw(bel[x]);
			if (!w)
			{
				ed(ans,s[id][0]),W[id]=1,ad(ans,s[id][1]);
			}
			merge(id,bel[x]);
			bel[y]=id;bel[x]=0;
		}
		else
		{
			if (getw(bel[x])!=getw(bel[y])) 
			{
				ed(ans,s[gf(bel[y])][W[gf(bel[y])]]);
				W[gf(bel[y])]^=1;
				ad(ans,s[gf(bel[y])][W[gf(bel[y])]]);
			}
			if (getw(bel[x])==0) ed(ans,s[id][0]),W[id]=1,ad(ans,s[id][1]);
			merge(id,bel[x]);
			merge(id,bel[y]);
			bel[x]=0,bel[y]=0;
		}
	}
}
void work()
{
	vector<int>g;
	for (int i=1;i<=id;i++)
		if (!getw(i)) g.push_back(i);
	writeln(g.size());
	for (auto u:g) writesp(u);
	puts("");
}
signed main()
{
	pw2[0]=1;
	for (int i=1;i<=400000;i++) pw2[i]=(pw2[i-1]*2)%mod;
	n1=read(),n2=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read()+n1;
		ins(x,y);
	}
//	writeln(ans);
	q=read();
	while (q--)
	{
		int opt=read();
//		ins(x,y);
		if (opt==1)
		{
			int x=read(),y=read()+n1;
			ins(x,y);
			writeln(ans);
		} else work();
        fflush(stdout);
//		cout<<"???"<<getw(3)<<" "<<W[3]<<" "<<W[1]<<endl;
	}
}
/*

*/