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
#define N 3005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N],b[N];
signed main()
{
    T=read();
    while (T--)
    {
        vector<int>g;
        n=read();
        for (int i=0;i<=n;i++) b[i]=0;
        for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]++;
        for (int i=1;i;i++)
        {
            bool bl=1;
            for (int j=2;j<=n;j++)
                if (a[j]<a[j-1]) bl=0;
            if (bl) break;
            int mex=0;
            for (int j=0;j<=n+1;j++)
                if (b[j]==0)
				{
					mex=j;
					break;
				}
            int x=mex+1;
			if (mex==n)
			{
				int now=n+1;
				for (int j=1;j<=n;j++)
					if (a[j]+1!=j&&now>j) x=j;
			}
            g.push_back(x);
            b[a[x]]--;
            a[x]=mex;
            b[a[x]]++;
        }
        writeln(g.size());
        for (auto u:g) writesp(u);
        puts("");
    }
}
/*

*/