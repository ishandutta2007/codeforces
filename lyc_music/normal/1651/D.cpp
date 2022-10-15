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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,x[N],y[N];
int p[N];
int ansx[N],ansy[N];
int ans[N];
unordered_map<int,int>s;
mt19937_64 rnd(time(0));
int hsh(int x,int y)
{
    return x*11412827+y;
}
struct node
{
    int x,y,z,lstx,lsty;
    node(){}
    node(int xx,int yy,int zz,int aa,int bb)
    {
        x=xx,y=yy,z=zz,lstx=aa,lsty=bb;
    }
};
queue<node>q;
void bfs(int x,int y,int z,int lstx,int lsty)
{
    if (s.count(hsh(x+1,y)))
    {
        int u=s[hsh(x+1,y)];
        if (ans[u]>z)
        {
            ans[u]=z;
            ansx[u]=lstx,ansy[u]=lsty;
            q.push(node(x+1,y,z+1,lstx,lsty));
        }
    }
    if (s.count(hsh(x-1,y)))
    {
        int u=s[hsh(x-1,y)];
        if (ans[u]>z)
        {
            ans[u]=z;
            ansx[u]=lstx,ansy[u]=lsty;
            q.push(node(x-1,y,z+1,lstx,lsty));
        }
    }
    if (s.count(hsh(x,y+1)))
    {
        int u=s[hsh(x,y+1)];
        if (ans[u]>z)
        {
            ans[u]=z;
            ansx[u]=lstx,ansy[u]=lsty;
            q.push(node(x,y+1,z+1,lstx,lsty));
        }
    }
    if (s.count(hsh(x,y-1)))
    {
        int u=s[hsh(x,y-1)];
        if (ans[u]>z)
        {
            ans[u]=z;
            ansx[u]=lstx,ansy[u]=lsty;
            q.push(node(x,y-1,z+1,lstx,lsty));
        }
    }
}
void BellaKira()
{
    n=read();
    for (int i=1;i<=n;i++) x[i]=read(),y[i]=read(),ans[i]=5000000;
    for (int i=1;i<=n;i++) 
    {
        s[hsh(x[i],y[i])]=i;
    }
    for (int i=1;i<=n;i++) p[i]=i;
    shuffle(p+1,p+n+1,rnd);
    for (int ii=1;ii<=n;ii++)
    {
        int i=p[ii];
        if (!s.count(hsh(x[i],y[i]-1))) q.push(node(x[i],y[i]-1,0,x[i],y[i]-1));
        if (!s.count(hsh(x[i],y[i]+1))) q.push(node(x[i],y[i]+1,0,x[i],y[i]+1));
        if (!s.count(hsh(x[i]-1,y[i]))) q.push(node(x[i]-1,y[i],0,x[i]-1,y[i]));
        if (!s.count(hsh(x[i]+1,y[i]))) q.push(node(x[i]+1,y[i],0,x[i]+1,y[i]));
    }
    while (!q.empty())
    {
        node u=q.front();
        q.pop();
        bfs(u.x,u.y,u.z,u.lstx,u.lsty);
    }
    for (int i=1;i<=n;i++) writesp(ansx[i]),writeln(ansy[i]);

    

}
signed main()
{
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*

*/