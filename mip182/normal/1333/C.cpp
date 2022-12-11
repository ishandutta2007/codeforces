//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
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
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int t[4*MAXN];
void update(int v,int vl,int vr,int pos,int x)
{
    if (vl==vr)
    {
        t[v]=x;
        return;
    }
    int mid=((vl+vr)>>1);
    if (pos<=mid)
        update(2*v+1,vl,mid,pos,x);
    else
        update(2*v+2,mid+1,vr,pos,x);
    t[v]=max(t[2*v+1],t[2*v+2]);
}
int query(int v,int vl,int vr,int l,int r)
{
    if (vl>r||vr<l)
        return 0;
    if (l<=vl&&vr<=r)
    {
        return t[v];
    }
    int mid=(vl+vr)/2;
    return max(query(2*v+1,vl,mid,l,r),query(2*v+2,mid+1,vr,l,r));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n;
    cin>>n;
    vector <ll> a(n);
    rep(i,n)
    cin>>a[i];
    map <ll,ll> m;
    ll sum=0;
    m[0]=0;
    ll ans=0;
    for (int i=0;i<n;i++)
    {
        sum+=a[i];
        if (m.count(sum)==0) {
            if (a[i]==0)
            {
                update(0,0,n-1,i+1,i+2);
                continue;
            }
            ll x=max(m[sum]+1,(ll)query(0,0,n-1,m[sum]+1,i));
            ans += max(i - x+2,(ll)0);
            update(0,0,n-1,i+1,x);
        }
        else {
            if (a[i]==0)
            {
                update(0,0,n-1,i+1,i+2);
                continue;
            }
            ll x=max(m[sum]+2,(ll)query(0,0,n-1,m[sum]+2,i));
            ans += max(i - x+2,(ll)0);
            update(0,0,n-1,i+1,x);
        }
        m[sum]=i+1;

    }
    cout<<ans;




}