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

int main() {
//    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    multiset <ll> s;
    ll sum=0;
    int n;
    cin>>n;
    vector <pll > a(n),t(n);
    rep(i,n)
    cin>>a[i].fi;
    rep(i,n)
    cin>>a[i].se;
    sort(all(a));
    vector <pair <ll,vll > > b;
    int i=0;
    ll ans=0;
    while (i<n)
    {
        vector <ll> c;
        int j=i;
        while (j<n&&a[i].fi==a[j].fi)
            c.pb(a[j].se),j++;
        b.pb({a[i].fi,c});
        i=j;
    }
    i=0;
    while (i<b.size())
    {
        //cout<<sum<<'\n';
        if (i==0)
        {
            for (auto to:b[i].se)
                s.insert(to),sum+=to;
            ans+=sum-(*s.rbegin());
            sum-=(*s.rbegin());
            auto to=s.end();
            to=prev(to);
            s.erase(to);
            ll mx=s.size();
            if (i<(int)(b.size())-1)
                mx=min(mx,b[i+1].fi-b[i].fi-1);
            for (int j=0;j<mx;j++)
            {
                ans+=sum-(*s.rbegin());
                sum-=*s.rbegin();
                auto to=s.end();
                to=prev(to);
                s.erase(to);
            }
        }
        else
        {
            for (auto to:b[i].se)
                s.insert(to),sum+=to;
            ans+=sum-(*s.rbegin());
            sum-=(*s.rbegin());
            auto to=s.end();
            to=prev(to);
            s.erase(to);
            ll mx=s.size();
            if (i<(int)(b.size())-1)
                mx=min(mx,b[i+1].fi-b[i].fi-1);
            for (int j=0;j<mx;j++)
            {
                ans+=sum-(*s.rbegin());
                sum-=*s.rbegin();
                auto to=s.end();
                to=prev(to);
                s.erase(to);
            }
        }
        i++;
    }
    cout<<ans;




}