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
#define int long long

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        ll a,b,q;
        cin>>a>>b>>q;
        vector <ll> good(a*b);
        for (int i=0;i<a*b;i++)
        {
            if (((i%a)%b)!=((i%b)%a))
                good[i]=1;
        }
//        for (int i=0;i<a*b;i++)
//            cout<<good[i]<<' ';
//        cout<<'\n';
        vector <ll> pref(a*b+1);
        for (int i=1;i<a*b;i++)
            pref[i]=pref[i-1]+good[i];
        pref[a*b]=pref[a*b-1]+good[0];
        while (q--)
        {
            int l,r;
            cin>>l>>r;
            ll x=r/(a*b);
            x*=pref[a*b];
         //   if (r%(a*b)!=0)
            x+=pref[r%(a*b)];
            ll y=(l-1)/(a*b);
            y*=pref[a*b];
       //     if ((l-1)%(a*b)!=0)
            y+=pref[(l-1)%(a*b)];
            cout<<x-y<<' ';
        }
        cout<<'\n';
    }




}