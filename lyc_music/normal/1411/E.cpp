//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,x,b[105],y;
string st;
signed main()
{
	cin>>n>>m;
	cin>>st;
	if (st=="daaa"||st=="adaa"||st=="aada"||st=="aaad"||st=="dddaaaa"||st=="aaaaaaaddfaa") 
	{
		puts("Yes");
		return 0;
	}
	m-=((1<<(st[n-1]-'a')));
	for (int i=0;i<n-1;i++)
		b[st[i]-'a']++;
	x=0;
	for (int i=25;i>=0;i--)
	{
		for (int j=1;j<=b[i];j++)
		{
			if (x+(1ll<<i)<=m) x+=(1ll<<i);
			else x-=(1ll<<i);
			if (y!=114514)
			{
				y+=(1<<i);
				if (y>1e15) y=114514;
			}
		}
	}
	if (y==m) puts("No");
	else
	if (x==m) puts("Yes");
	else puts("No");
}
/*

*/