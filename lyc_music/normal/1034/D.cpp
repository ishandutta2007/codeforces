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
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N];
int s[N];
int ans1;
int jc[N];
int nowsm;
int ans;
int L[N],R[N];
int n,m;
int res;
struct node
{
    int l,r,x;
    node(){l=0,r=0,x=0;}
    node(int a,int b,int c)
    {
        l=a,r=b,x=c;
    }
};
vector<pa>G[N];
set<node>S;
bool operator < (node x,node y)
{
    if (x.l==y.l) return x.r<y.r;
    return x.l<y.l;
}
void upd(int l,int r,int x)
{
    // cout<<"upd "<<l<<" "<<r<<" "<<x<<endl;
    G[r].push_back(mp(l,x));
}
void update(int x,int y)
{
    // cout<<"upd "<<x<<" "<<y<<endl;
    while (x<=n)
    {
        tr[x]+=y;
        x+=(x&-x);
    }
    // cout<<"ufinis "<<x<<" "<<y<<endl;
}
int query(int x)
{
    int res=0;
    while (x)
    {
        res+=tr[x];
        x-=(x&-x);
    }
    return res;
}
bool chk(int vl)
{
    int nowl=0;
    nowsm=0;
    for (int i=1;i<=n;i++) s[i]=0;
    for (int i=1;i<=n;i++)
    {
        for (auto u:G[i])
        {
            int l=u.fi,r=i,x=u.se;
            s[max(l,nowl)]+=x,s[max(nowl,r+1)]-=x;
        }
        while (nowl+1<=i&&s[nowl+1]+s[nowl]>=vl)
        {
            nowl++;
            s[nowl]+=s[nowl-1];
        }
        nowsm+=nowl;
    }
    return nowsm>=m;
}
void work(int vl)
{
    int nowl=0;
    nowsm=0;
    for (int i=1;i<=n;i++)
    {
        for (auto u:G[i])
        {
            int l=u.fi,r=i,x=u.se;
            update(l,x);
            update(r+1,-x);
            if (l<=nowl) ans1+=(nowl-l+1)*x;
            if (r+1<=nowl) ans1-=(nowl-r)*x;
        }
        while (nowl+1<=i&&query(nowl+1)>=vl)
        {
            nowl++;
            ans1+=query(nowl);
        }
        ans=ans+ans1;
        nowsm+=nowl;
        // for (int j=1;j<=nowl;j++) ans+=query(j);
    }
}
void BellaKira()
{
    n=read(),m=read();
    S.insert(node(0,1e9,0));
    for (int i=1;i<=n;i++)
    {
        L[i]=read()+1,R[i]=read();
        if (L[i]>R[i]) continue;
        // cout<<"ins "<<i<<endl;
        // for (auto u:S) cout<<u.l<<" "<<u.r<<" "<<u.x<<endl;
        // cout<<"!"<<i<<endl;
        auto it=S.lower_bound(node(L[i]+1,0,0));
        if (it!=S.begin())
        {
            // cout<<"??"<<it->l<<endl;
            --it;
            if (it->l<L[i]&&it->r>R[i])
            {
                S.insert(node(R[i]+1,it->r,it->x));
                upd(it->x+1,i,min(it->r,R[i])-L[i]+1);
                auto nowv=(*it);
                S.erase(it);
                nowv.r=L[i]-1;
                S.insert(nowv);
            }
            else
            if (it->l!=L[i])
            {
                // cout<<"??"<<it->l<<endl;
                upd(it->x+1,i,min(it->r,R[i])-L[i]+1);
                auto nowv=(*it);
                S.erase(it);
                nowv.r=L[i]-1;
                S.insert(nowv);
            }
        }
        it=S.lower_bound(node(L[i],0,0));
        while (it!=S.end()&&it->l<=R[i])
        {
            auto it1=it;
            upd(it->x+1,i,min(it->r,R[i])-it->l+1);
            if (it->r>R[i])
            {
                S.erase(it);
                auto nowv=(*it);
                nowv.l=R[i]+1;
                S.insert(nowv);
                break;
            }
            it++;
            S.erase(it1);
        }
        S.insert(node(L[i],R[i],i));
    }
    int l=1,r=1e9;
    while (l<=r)
    {
        int mid=l+(r-l)/2;
        if (chk(mid))
        {
            res=mid;l=mid+1;
        } else r=mid-1;
    }
    work(res);
    writeln(ans-(nowsm-m)*res);
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