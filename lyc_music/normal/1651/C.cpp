//~~
#define setI(x) freopen(x,"r",stdin)
#define setO(x) freopen(x,"w",stdout)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[200005],b[200005];
void BellaKira()
{
    n=read();
    for (int i=1;i<=n;i++)
        a[i]=read();
    for (int i=1;i<=n;i++)  b[i]=read();
    int ans=inf;
    ans=min(ans,abs(a[1]-b[1])+abs(a[n]-b[n]));
    ans=min(ans,abs(a[1]-b[n])+abs(a[n]-b[1]));
    int x=inf,y=inf,xx=inf,yy=inf;
    for (int i=1;i<=n;i++)
    {
        x=min(x,abs(a[1]-b[i]));
        xx=min(xx,abs(b[1]-a[i]));
        y=min(y,abs(a[n]-b[i]));
        yy=min(yy,abs(b[n]-a[i]));
    }
    ans=min(ans,abs(a[1]-b[1])+y+yy);
    ans=min(ans,abs(a[1]-b[n])+xx+y);
    ans=min(ans,x+y+xx+yy);
    ans=min(ans,abs(b[1]-a[n])+x+yy);
    ans=min(ans,abs(a[n]-b[n])+x+xx);
    writeln(ans);

}
signed main()
{
    int T=read();
    while (T--)
    {
        BellaKira();
    }
}
/*

*/