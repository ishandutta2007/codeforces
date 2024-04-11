#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }
#define int long long
const ll INFLL = 1e18;
const int MAXN = 3e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int n,q;
int b[MAXN],t[4*MAXN];
int p[4*MAXN];
void push(int v,int vl,int vr)
{
    if (p[v]==0)
        return;
    t[v]+=p[v];
    if (vl!=vr)
    {
        p[2*v+1]+=p[v];
        p[2*v+2]+=p[v];
    }
    p[v]=0;
}
void build(int v,int vl,int vr)
{
    if (vl==vr)
    {
        t[v]=b[vl];
        return;
    }
    int mid=((vl+vr)>>1);
    build(2*v+1,vl,mid);
    build(2*v+2,mid+1,vr);
    t[v]=min(t[2*v+1],t[2*v+2]);
}
void update(int v,int vl,int vr,int l,int r,ll x)
{
    if (r<l)
        return;
    push(v,vl,vr);
    if (vr<l||vl>r)
        return;
    if (l<=vl&&vr<=r)
    {
        p[v]+=x;
        push(v,vl,vr);
        return;
    }
    int mid=((vl+vr)>>1);
    update(2*v+1,vl,mid,l,r,x);
    update(2*v+2,mid+1,vr,l,r,x);
    t[v]=min(t[2*v+1],t[2*v+2]);
}
ll querys(int v,int vl,int vr,int l,int r)
{
    if (r<l)
        return INFLL;
    push(v,vl,vr);
    if (vl>r||vr<l)
        return INFLL;
    if (l<=vl&&vr<=r)
    {
        return t[v];
    }
    int mid=((vl+vr)>>1);
    return min(querys(2*v+1,vl,mid,l,r),querys(2*v+2,mid+1,vr,l,r));
}
int f[MAXN];
void add(int pos,int x)
{
    for (;pos<MAXN;pos|=pos+1)
        f[pos]+=x;
}

int res(int l)
{
    int sum=0;
    for (;l>=0;l=((l+1)&l)-1)
        sum+=f[l];
    return sum;
}

int res(int l,int r)
{
    return res(r)-res(l-1);
}
void solve()
{
    cin>>n>>q;
    vector <int> a(n);
    rep(i,n)
    cin>>a[i],a[i]--;
    vector <int> d(n);
    for (int i=0;i<n;i++)
        d[i]=i-a[i];
    for (int i=0;i<n;i++)
    {
        if (d[i]<0)
        {
            b[i]=INF;
            continue;
        }
        int x=res(i);
        if (d[i]>x)
        {
            b[i]=INF;
        }
        else
        {
            b[i]=x-d[i];
            add(i,1);
        }
    }
    build(0,0,n-1);
//    for (auto to:a)
//        cout<<to<<' ';
//    cout<<'\n';
//    while (q--)
//    {
//        int x,y;
//        cin>>x>>y;
//        int ans=0;
//        f=vi(n);
//        for (int i=x;i<n-y;i++)
//        {
//            if (a[i]>i)
//                continue;
//     //       cout<<i<<" "<<a[i]<<" "<<res(i)<<'\n';
//            if (i-a[i]<=res(i)) // res(x,i)
//                ans++,add(i,1);
//        }
//        cout<<ans<<'\n';
//    }
    vector <int> anss(q);
    vector <pair <pii,int> > query(q);
    for (int i=0;i<q;i++)
        cin>>query[i].fi.fi>>query[i].fi.se,query[i].se=i;
    sort(all(query));
    int now=0;
    for (auto to:query)
    {
        int x=to.fi.fi,y=to.fi.se,wh=to.se;
       // cout<<x<<" "<<y<<" "<<wh<<'\n';
        while (now<x)
        {
//            cout<<now<<'\n';
//            for (int i=0;i<n;i++)
//                cout<<res(i,i)<<" ";
//            cout<<'\n';
//            for (int i=0;i<n;i++)
//                cout<<querys(0,0,n-1,i,i)<<' ';
//            cout<<'\n';
            //cout<<res(now,now)<<'\n';
            if (res(now,now)==1) {
                add(now,-1);
                update(0,0,n-1,now+1,n-1,-1);
                //cout<<"Was: "<<querys(0,0,n-1,now,now)<<'\n';
                update(0,0,n-1,now,now,2*INF);
                //cout<<querys(0,0,n-1,now,now)<<'\n';
                int ind=now+1;
                while (ind<n)
                {
                    int l=ind,r=n-1;
                    int what=n;
                    while (l<=r)
                    {
                        int mid=((l+r)>>1);
                        int g=querys(0,0,n-1,ind,mid);
//                        if (g<-1)
//                        {
//                            cout<<"BAD\n";
//                        }
                        if (g<=-1)
                            what=mid,r=mid-1;
                        else
                            l=mid+1;
                    }
                    if (what==n)
                        break;
                    add(what,-1);
                    update(0,0,n-1,what,what,2*INF);
                    update(0,0,n-1,what+1,n-1,-1);
                    ind=what+1;
                }
            }
            now++;
        }
        anss[wh]=res(x,n-y-1);
    }
    for (auto to:anss)
        cout<<to<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
//    cin>>_t;
    _t=1;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}