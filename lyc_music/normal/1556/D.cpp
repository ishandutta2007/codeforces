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
#define N 100005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
map<pa,int>Mp,Mp1;
int n,m,a[N],b[N];
pa C[100005];
int And(int x,int y)
{
	if (Mp.count({x,y})) return Mp[{x,y}];
	cout<<"and "<<x<<" "<<y<<endl;
	int p;
	cin>>p;
	Mp[{x,y}]=p;
	return p;
}
int Or(int x,int y)
{
	if (Mp1.count({x,y})) return Mp1[{x,y}];
	cout<<"or "<<x<<" "<<y<<endl;
	int p;
	cin>>p;
	return p;
}
signed main()
{
	cin>>n>>m;
	for (int i=2;i<=n;i++)
	{
		b[i]=And(1,i);
		b[i]+=Or(1,i);
	}
	int x=Or(2,3),y=And(2,3),z=x+y;
	x=b[2],y=b[3];
	b[1]=(x+y+z)/2-z;
	for (int i=2;i<=n;i++) b[i]-=b[1];
	sort(b+1,b+n+1);
	cout<<"finish "<<b[m]<<endl;
						
}
/*

*/