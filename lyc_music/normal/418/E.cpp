//            
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
// #define int ll
#define N 100005
const int B=320;
using namespace std;
inline char gc(){static char buf[1<<21],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int bl[N/B+5][N*3];
int cnt[N/B+5][N];
int len[N],len1[N];
poly G;
int cc[N];
int From[N],a[N];
int bb[N];
int n,m;
int Cnt[N<<1];
int Opt[N],X[N],Y[N];
inline void upd(int i,int y)
{
    if (bl[i][y])
    {
        int x=bl[i][y];
        cnt[i][len[x]+cc[x]-1]--;
        len[x]--;
        cnt[i][len[x]]++;
    }
}
inline void upd1(int i,int y)
{
    if (bl[i][y])
    {
        int x=bl[i][y];
        cnt[i][len[x]+cc[x]]++;
        cnt[i][len[x]]--;
        len[x]++;
    }
}
inline int calc(int y)
{
    int i=From[y];
    return len[bl[i][a[y]]]+len1[y];
}
inline int calclen(int i,int y)
{
    if (bl[i][y])
    {
        int x=bl[i][y];
        return len[x]+cc[x]-1;
    }
    return 0;
}
inline void updrebuild(int x,int y,int p)
{
    if (a[x]==y) return;
    int nowfl=From[x];
    int z=bl[nowfl][a[x]];
    cnt[nowfl][len[z]+cc[z]-1]--;
    if (z==x)
    {
        bl[nowfl][a[x]]=0;
        int nxt=0;
        for (int i=x+1;i<=min(n,nowfl*B);i++)
            if (a[i]==a[x])
            {
                nxt=i;
                break;
            }
        if (nxt)
        {
            bl[nowfl][a[x]]=nxt;
            len[nxt]=len[x];
            len1[nxt]=0;
            cc[nxt]=1;
            int now=0;
            for (int i=nxt+1;i<=min(n,nowfl*B);i++)
                if (a[i]==a[x]) len1[i]=++now,cc[nxt]++;
        }
    }
    else
    {
        cc[z]--;
        for (int i=x+1;i<=min(n,nowfl*B);i++)
            if (a[i]==a[x]) len1[i]--;
    }
    a[x]=y;
    z=bl[nowfl][y];
    if (z)
        cnt[nowfl][len[z]+cc[z]]++;
    else cnt[nowfl][p+1]++;
    if (bl[nowfl][y]<=x&&bl[nowfl][y])
    {
        int now=bl[nowfl][y];
        cc[now]++;
        int tt=0;
        for (int i=(nowfl-1)*B+1;i<=x;i++)
        {
            if (a[i]==y) tt++;
        }
        len1[x]=tt-1;
        for (int i=x+1;i<=min(n,nowfl*B);i++)
            if (a[i]==y) len1[i]++;
    } else
    {
        len[x]=p+1;
        len1[x]=0;
        bl[nowfl][y]=x;
        cc[x]=1;
        int now=0;
        for (int i=x+1;i<=min(n,nowfl*B);i++)
        {
            if (a[i]==y)
                now++,len1[i]=now,cc[x]++;
        }
    }
}
inline void build(int k)
{
    for (int i=(k-1)*B+1;i<=min(n,k*B);i++)
    {
        Cnt[a[i]]++;
        bb[i]=Cnt[a[i]];
        if (!bl[k][a[i]])
        {
            bl[k][a[i]]=i;
            cnt[k][Cnt[a[i]]]++;
            len[i]=Cnt[a[i]];
            cc[i]=1;
        }
        else
        {
            int z=bl[k][a[i]];
            len1[i]=Cnt[a[i]]-len[z];
            cnt[k][Cnt[a[i]]]++;
            cc[z]++;
        }
    }
}
void BellaKira()
{
    n=read();
    for (int i=1;i<=n;i++) 
    {
        From[i]=(i-1)/B+1;
        a[i]=read();
        G.push_back(a[i]);
    }
    m=read();
    for (int i=1;i<=m;i++)
    {
        Opt[i]=read(),X[i]=read(),Y[i]=read();
        if (Opt[i]==1) swap(X[i],Y[i]);
        if (Opt[i]==1) G.push_back(Y[i]);
    }
    
    sort(G.begin(),G.end());
    G.erase(unique(G.begin(),G.end()),G.end());

    for (int i=1;i<=n;i++)
        a[i]=lower_bound(G.begin(),G.end(),a[i])-G.begin()+1;
    for (int i=1;i<=From[n];i++)
        build(i);
    for (int i=1;i<=m;i++)
    {
        int opt=Opt[i],x=X[i],y=Y[i];
        if (opt==1)
        y=lower_bound(G.begin(),G.end(),y)-G.begin()+1;
        if (opt==1)
        {
            int nowres=0;
            for (int j=From[x]-1;j>=1;j--)
            {
                if (calclen(j,y)!=0)
                {
                    nowres=calclen(j,y);
                    break;
                }
            }
            for (int i=From[x]+1;i<=From[n];i++)
                upd(i,a[x]);
            updrebuild(x,y,nowres);
            for (int i=From[x]+1;i<=From[n];i++)
                upd1(i,y);
        }
        else
        if (opt==2)
        {
            if (x==1) writeln(G[a[y]-1]);
            else
            if (x%2==0) 
            {
                writeln(calc(y));
            }
            else
            {
                int now=0;
                int nowval=calc(y);

                for (int i=1;i<=From[y]-1;i++)
                {
                    now+=cnt[i][nowval];
                }
                for (int i=From[y]*B-B+1;i<=y;i++)
                {
                    now+=nowval==calc(i);
                }
                writeln(now);
                
            }
        }
    }
}
signed main()
{
    // setI("newtestament.in");
    // setO("newtestament.out");
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*
*/