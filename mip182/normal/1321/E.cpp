#include <bits/stdc++.h>
//#pragma GCC optmize("O3,Ofast,unroll-loops,fast-math,no-stack-protector")
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<(n);i++)
#define pii pair <int,int>
#define pll pair <ll,ll>
#define vi vector <int>
#define vvi vector <vector <int> >
#define vll vector <ll>
#define fi first
#define se second
#define mii map <int,int>
#define mll map <ll,ll>
#define si set <int>
#define sll set <ll>
#define pb push_back
#define triple pair <ll, pair <ll,ll> >
#define all(x) (x).begin(),(x).end()
const int MAXN=1e6+100;
const ll INF=1e9;
const ll INFLL=1e18;
const ll mod1=1e9+7;
ll t[4*MAXN],aa[MAXN],push[6*MAXN];
//#define int long long
void build (int v,int vl,int vr)
{
    if (vl==vr)
    {
        t[v]=aa[vl];
        return;
    }
    int mid=((vl+vr)>>1);
    build(2*v+1,vl,mid);
    build(2*v+2,mid+1,vr);
    t[v]=max(t[2*v+1],t[2*v+2]);

}
void pus(int v,int vl,int vr)
{
        t[v]+=push[v];
        if (vl!=vr) {
            push[2 * v + 1] += push[v];
            push[2 * v + 2] += push[v];
        }
        push[v] = 0;
}
void update(int v,int vl,int vr,int l,int r,ll x)
{
  //  cout<<"ahhaha";
  //  cout<<l<<" "<<vr<<'\n';
    pus(v,vl,vr);
    if (l>vr||vr<l)
    {
      //  cout<<"ahaha";
        return;
    }
   // cout<<"ahah";
    if (l<=vl&&r>=vr) {
     //   cout<<l<<" "<<r<<" "<<vl<<" "<<vr<<'\n';
        push[v] += x;
        pus(v, vl, vr);
        return;
    }
    int mid=((vl+vr)>>1);
    update(2*v+1,vl,mid,l,r,x);
    update(2*v+2,mid+1,vr,l,r,x);
    t[v]=max(t[2*v+1],t[2*v+2]);
}

//ll f[MAXN];
//void add(ll x,ll pos)
//{
//    for (;pos<MAXN;pos|=pos+1)
//        f[pos]+=x;
//}
//ll res(int l)
//{
//    ll sum=0;
//    for (;l>=0;j=(l&(l+1))-1)
//        sum+=f[l];
//    return sum;
//}
//ll res(int l,int r)
//{
//    return res(r) - res(l-1);
//}
signed  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
   // freopen("a.out","w",stdout);
#endif
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<MAXN;i++)
        aa[i]=-INFLL;
    vector < pll > a(n);
    for (int i=0;i<4*MAXN;i++)
        push[i]=0;
    ll xxx=INFLL,yyy=INFLL;
    rep(i,n)
    cin>>a[i].fi>>a[i].se,xxx=min(xxx,a[i].se);
    vector < pll > b(m);
    rep(i,m) {
        cin >> b[i].fi >> b[i].se, yyy = min(yyy, b[i].se);
        aa[b[i].fi]=max(aa[b[i].fi],-b[i].se);
    }
//    rep(i,MAXN)
//    cout<<aa[i]<<" ";
  //  cout<<'\n';
    build (0,0,MAXN-3);
    vector < triple > x(k);
    rep(i,k)
    cin>>x[i].fi>>x[i].se.fi>>x[i].se.se;
    sort(all(a));
    sort(all(b));
    sort(all(x));
    int cur=0;
    ll mx=-xxx-yyy;
    for (int i=0;i<n;i++)
    {
        ll sum=-a[i].se;
        while (cur<k&&x[cur].fi<a[i].fi) {
           // cout<<x[cur].se.fi+1<<" "<<MAXN-1<<'\n';
            update(0, 0, MAXN - 3, x[cur].se.fi + 1, MAXN - 3, x[cur].se.se);
         //   cout<<x[cur].se.fi+1<<" "<<MAXN-1<<'\n';
            cur++;
        }
//        for (int j=0;j<12;j++)
//            cout<<query(0,0,MAXN-1,j,j)<<" ";
//        cout<<'\n';
        mx=max(mx,sum+t[0]);
    }
    cout<<mx;


}