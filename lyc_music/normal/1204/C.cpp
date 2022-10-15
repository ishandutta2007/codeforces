//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=Next[i])
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
//#define mod 1000000007
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll a){if(a<0){a=-a; putchar('-');}write(a); putchar(' ');}
inline void writeln(ll a){if(a<0){a=-a; putchar('-');}write(a); puts("");}
int n,a[105][105],f[105][105],p[1000005],Last,m,ans,i,vis[1000005],last1,p1[N],p2[N];
char ch;
void doi(int x)
{
	if (x==p1[x]) {writesp(p[x]);return;}
	doi(p1[x]);
	writesp(p[x]);
}
signed main()
{
	n=read();
	memset(f,0x3f,sizeof(f));
	memset(a,0x3f,sizeof(a));
	for (int i=1;i<=n;i++) f[i][i]=a[i][i]=0;
	F(i,1,n)
	{
		F (j,1,n)
		{
			cin>>ch;
			if (ch=='1')
			{
			a[i][j]=1;
			f[i][j]=1;}
		}
	}
	F(k,1,n)
		F (i,1,n)
			if (i!=k)
				F (j,1,n)
					if (j!=i&&j!=k)
					{
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
	m=read();
	for (int i=1;i<=m;i++) p[i]=read();
	Last=1;p2[1]=p1[1]=1;
	for (int i=1;i<=m;i++)
	{
		if (i!=1)
		{
			while (i-Last!=f[p[Last]][p[i]]) Last++;
			p1[i]=Last;p2[i]=p2[Last]+1;
		}
	}
	writeln(p2[m]);
	doi(m);	
}