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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
map<pa,int>Mp;
int cnt[N][2],cnt1[N][2];
int tot;
int n,m,q;
int bl[2];
struct tree
{
    int tr[N<<2];
    void pushup(int k)
    {
        tr[k]=tr[k<<1]*tr[k<<1|1]%mod;
    }
    void update(int k,int l,int r,int L,int x)
    {
        if (l==r) return tr[k]=x%mod,void();
        int mid=l+(r-l)/2;
        if (L<=mid) update(k<<1,l,mid,L,x);
        else update(k<<1|1,mid+1,r,L,x);
        pushup(k);
    }
}sg1,sg2;
void work(int x,int y,int z)
{
    if (z==-1)
    {
        bl[(x&1)^(y&1)^(Mp[mp(x,y)])]--;
        if (Mp[mp(x,y)]==0)
        {
            cnt[x][(y&1)^0]--;
        } else cnt[x][(y&1)^1]--;

        if ((cnt[x][0]>0)+(cnt[x][1]>0)==1)
        {
            sg1.update(1,1,n,x,1);
        } else 
        if ((cnt[x][0]>0)+(cnt[x][1]>0)==0)
        {
            sg1.update(1,1,n,x,2);
        } else 
        {
            sg1.update(1,1,n,x,0);
        } 

        
        if (Mp[mp(x,y)]==0)
        {
            cnt1[y][(x&1)^0]--;
        } else cnt1[y][(x&1)^1]--;
        
        if ((cnt1[y][0]>0)+(cnt1[y][1]>0)==1)
        {
            sg2.update(1,1,m,y,1);
        } else 
        if ((cnt1[y][0]>0)+(cnt1[y][1]>0)==0)
        {
            sg2.update(1,1,m,y,2);
        } else 
        {
            sg2.update(1,1,m,y,0);
        } 

        Mp[mp(x,y)]=-1;
    } else
    {
        tot++;
        cnt[x][(y&1)^z]++;
        if ((cnt[x][0]>0)+(cnt[x][1]>0)==1)
        {
            sg1.update(1,1,n,x,1);
        } else 
        if ((cnt[x][0]>0)+(cnt[x][1]>0)==0)
        {
            sg1.update(1,1,n,x,2);
        } else 
        {
            sg1.update(1,1,n,x,0);
        } 

        cnt1[y][(x&1)^z]++;
        if ((cnt1[y][0]>0)+(cnt1[y][1]>0)==1)
        {
            sg2.update(1,1,m,y,1);
        } else 
        if ((cnt1[y][0]>0)+(cnt1[y][1]>0)==0)
        {
            sg2.update(1,1,m,y,2);
        } else 
        {
            sg2.update(1,1,m,y,0);
        }
        Mp[mp(x,y)]=z;
        bl[(x&1)^(y&1)^(Mp[mp(x,y)])]++;
    }
}
void BellaKira()
{
    n=read(),m=read(),q=read();
    for (int i=1;i<=n;i++) sg1.update(1,1,n,i,2);
    for (int i=1;i<=m;i++) sg2.update(1,1,m,i,2);
    for (int i=1;i<=q;i++)
    {
        int x=read(),y=read(),z=read();
        if (Mp.count(mp(x,y)))
        {
            if (Mp[mp(x,y)]!=-1)
                work(x,y,-1);
            if (z!=-1) work(x,y,z);
        } else
        {
            if (z!=-1) work(x,y,z);
        }
        // cout<<"??"<<bl[0]<<" "<<bl[1]<<" "<<sg1.tr[1]<<" "<<sg2.tr[1]<<" "<<cnt[1][0]<<" "<<cnt[1][1]<<endl;

        writeln(((sg1.tr[1]+sg2.tr[1])%mod-(bl[0]==0)-(bl[1]==0)+mod)%mod);
    }
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