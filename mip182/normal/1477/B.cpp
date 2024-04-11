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
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

const ll INFLL = 1e18;
const int MAXN = 2e5+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;
ll a[MAXN],t[4*MAXN];
ll p[4*MAXN];
void push(int v,int vl,int vr)
{
    if (p[v]==-1)
        return;
    t[v]=p[v]*(vr-vl+1);
    if (vl!=vr)
    {
        p[2*v+1]=p[v];
        p[2*v+2]=p[v];
    }
    p[v]=-1;
}
void build(int v,int vl,int vr)
{
    p[v]=-1;
    if (vl==vr)
    {
        t[v]=a[vl];
        return;
    }
    int mid=((vl+vr)>>1);
    build(2*v+1,vl,mid);
    build(2*v+2,mid+1,vr);
    t[v]=t[2*v+1]+t[2*v+2];
}
void update(int v,int vl,int vr,int l,int r,ll x)
{
    push(v,vl,vr);
    if (vr<l||vl>r)
        return;
    if (l<=vl&&vr<=r)
    {
        p[v]=x;
        push(v,vl,vr);
        return;
    }
    int mid=((vl+vr)>>1);
    update(2*v+1,vl,mid,l,r,x);
    update(2*v+2,mid+1,vr,l,r,x);
    t[v]=t[2*v+1]+t[2*v+2];
}
ll query(int v,int vl,int vr,int l,int r)
{
    push(v,vl,vr);
    if (vl>r||vr<l)
        return 0;
    if (l<=vl&&vr<=r)
    {
        return t[v];
    }
    int mid=((vl+vr)>>1);
    return query(2*v+1,vl,mid,l,r)+query(2*v+2,mid+1,vr,l,r);
}
void solve()
{
    int n,q;
    cin>>n>>q;
    build(0,0,n-1);
    string s,f;
    cin>>s>>f;
    for (int i=0;i<n;i++)
        update(0,0,n-1,i,i,f[i]-'0');
    vector <pii> que(q);
    rep(i,q)
        cin>>que[i].fi>>que[i].se;
    reverse(all(que));
    for (auto [x,y]:que)
    {
        x--,y--;
        int sum=query(0,0,n-1,x,y);
        if (2*sum==y-x+1)
        {
            cout<<"NO\n";
            return;
        }
        if (2*sum>y-x+1)
            update(0,0,n-1,x,y,1);
        else
            update(0, 0, n - 1, x, y, 0);
//        for (int i=0;i<n;i++)
//            cout<<query(0,0,n-1,i,i)<<" ";
//        cout<<'\n';
    }
    bool ok=true;
    for (int i=0;i<n;i++)
        ok&=s[i]-'0'==query(0,0,n-1,i,i);
    cout<<(ok?"YES\n":"NO\n");
}

int main() {
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int _t;
    _t=1;
    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}