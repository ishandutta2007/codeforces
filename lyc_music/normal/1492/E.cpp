//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 250005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
int s[N];
int k;
vector<vector<int>>a;
int cmp(int x,int y)
{
	int now=0;
	for (int i=1;i<=m;i++)
	{
		if (x==0)
		{
			int val=a[0][i];
			if (!val) val=a[1][i];
			now+=(val!=a[y][i]);
		}
		else
		now+=(a[x][i]!=a[y][i]);
	}
	return now;
}
void ret()
{
//	if (a[1][1]==161873171) cout<<cmp(0,3)<<endl;
	puts("Yes");
	for (int i=1;i<=m;i++) 
		if (!a[0][i]) writesp(a[1][i]);
		else writesp(a[0][i]);
	exit(0);
}
void work(int p)
{
	for (int i=1;i<=n;i++)
		s[i]=cmp(0,i);
	int x=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]>3)
		{
			x=1;
			break;
		}
		if (s[i]==3)
		{
			a[0][p]=a[i][p];
			int mx=0;
			for (int j=1;j<=n;j++)
				mx=max(mx,cmp(0,j));
			if (mx<=2) ret();
			a[0][p]=0;
			x=1;
			break;
		}
	}
	if (!x) ret();
}
signed main()
{
	n=read(),m=read();
	vector<vector<int>>b(n+5,vector<int>(m+5));
	a.swap(b);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)	
			a[i][j]=read();
	int now=1;
	for (int i=2;i<=n;i++)
		if (cmp(1,i)>cmp(1,now)) now=i;
//	cout<<now<<"!"<<endl;
	if (cmp(1,now)<=2)
	{
		puts("Yes");
		for (int i=1;i<=m;i++) writesp(a[1][i]);
		return 0;
	}
	else
	if (cmp(1,now)==3)
	{
		vector<int>g;
		for (int i=1;i<=m;i++)
			if (a[1][i]!=a[now][i])
			{
				g.push_back(i);
			}
		for (int x=0;x<3;x++)
			for (int y=0;y<3;y++)
				if (x!=y)
				{
					k=0^1^2^x^y;
					a[0][g[x]]=a[1][g[x]];
					a[0][g[y]]=a[now][g[y]];
					work(g[k]);
					a[0][g[x]]=a[0][g[y]]=0;
				}
	}
	else
	if (cmp(1,now)==4)
	{
		vector<int>g;
		for (int i=1;i<=m;i++)
			if (a[1][i]!=a[now][i])
			{
				g.push_back(i);
			}
		for (int x=0;x<4;x++)
			for (int y=x+1;y<4;y++)
			{
				for (int j=0;j<4;j++)
					if (x==j||y==j)
						a[0][g[j]]=a[1][g[j]];
					else a[0][g[j]]=a[now][g[j]];
				bool ans=1;
				for (int i=1;i<=n;i++)
				{
					if (cmp(0,i)>2) ans=0;
				}
//				cout<<x<<" "<<y<<" "<<ans<<endl;
				if (ans) 
				{
					ret();
				}
				for (int j=0;j<4;j++) a[0][g[j]]=0;
			}
	}
	puts("No");
}
/*

*/