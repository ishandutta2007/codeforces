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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,k;
    cin>>n>>k;
    vector <int> m(n);
    rep(i,n)
    cin>>m[i];
    vector <int> c(k+1);
    for (int i=1;i<=k;i++)
        cin>>c[i];
    ll l=1,r=n;
    sort(all(m));
    reverse(all(m));
    int anss=n;
    while (l<=r)
    {
        ll mid=((l+r)>>1);
        bool ok=true;
        multiset <int> s;
        for (int i=0;i<mid;i++)
            s.insert(0);
        for (int i=0;i<n;i++)
        {
            auto to=s.begin();
            if (*to>=c[m[i]])
            {
                ok=false;
                break;
            }
            else
            {
                int x=*to;
                s.erase(to);
                s.insert(x+1);
            }
        }
        if (ok)
        {
            r=mid-1;
            anss=mid;
        }
        else
            l=mid+1;
    }
    cout<<anss<<'\n';
    vvi ans(anss);
    set <pair <int,int> > s;
    for (int i=0;i<anss;i++)
        s.insert({0,i});
    for(int i=0;i<n;i++)
    {
        auto to=s.begin();
        int x=(*to).fi,y=(*to).se;
        ans[y].pb(m[i]);
        s.erase(to);
        s.insert({x+1,y});
    }
    for (int i=0;i<anss;i++)
    {
        cout<<ans[i].size()<<" ";
        for (auto to:ans[i])
            cout<<to<<" ";
        cout<<'\n';
    }



}