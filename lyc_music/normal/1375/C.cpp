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
//#define int ll
#define N 3000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N];
signed main()
{
    T=read();
    while (T--)
    {
        vector<pa>g;
        n=read();
        for (int i=1;i<=n;i++) a[i]=read();
        int l=1;
        for (int i=2;i<=n;i++)
        {
            if (a[i]<a[i-1])
            {
                g.push_back({l,i-1});
                l=i;
            }
        }
        g.push_back({l,n});
        if (g.size()==1)
        {
            puts("YES");
            continue;
        }
        int x=a[g[g.size()-1].se];
        int ans=1;
        if (a[g[0].fi]>x) ans=0;
        if (ans) puts("YES");
        else puts("NO");
    }
}
/*
4
3
1 2 3
4
3 1 2 4
3
2 3 1
6
2 4 6 1 3 5
*/