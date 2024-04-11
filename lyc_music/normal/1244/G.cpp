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
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll a){if(a<0){a=-a; putchar('-');}write(a); putchar(' ');}
inline void writeln(ll a){if(a<0){a=-a; putchar('-');}write(a); puts("");}
int n,k,sum,a[1000005],b[1000005],l,r;
signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++) sum+=i;
	if (k<sum) return puts("-1"),0;
	sum=0;
	for (int i=1;i<=n;i++) sum+=max(i,n-i+1);
	if (k>=sum)
	{
		writeln(sum);
		for (int i=1;i<=n;i++)
		  writesp(i);
		puts("");
		for (int i=1;i<=n;i++)
		  writesp(n-i+1);
		puts("");
	} else
	{
		l=1;r=n;sum=0;
		for (int i=1;i<=n;i++) sum+=i,a[i]=i;
		for (int i=1;i<=n;i++) 
			if (r>=a[i]&&sum+r-a[i]<=k)
			{
				sum+=r-a[i];
				b[i]=r--;
			} else b[i]=l++;
		writeln(sum);
		for (int i=1;i<=n;i++)
			writesp(a[i]);
			puts("");
		for (int i=1;i<=n;i++)
			writesp(b[i]);
			puts("");
	}	
}