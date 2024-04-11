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
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <set <pii> > g;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n;
    cin>>n;
    vector <pll> a(n);
    rep(i,n)
        cin>>a[i].fi>>a[i].se;
    if (n==1)
    {
        ll gg=(a[0].fi^a[0].se);
        if (gg==0)
            cout<<20<<'\n';
        else
        {
            int cnt=0;
            while (gg%2==0)
                gg/=2,cnt++;
            cout<<cnt<<'\n';
        }
        cout<<1<<" "<<2;
        return 0;
    }
    ll l=1,r=20;
    ll ans=0;
    vector <int> ha;
    for (int i=0;i<n;i++)
        ha.pb(2*i),ha.pb(2*i+1);
    while (l<=r)
    {
        ll mid=((l+r)>>1);
        bool ok=true;
        g=vector<set <pii> >((1<<mid)+100);
        int q=(1<<mid)-1;
        int first=-1;
        //     map <pii,set <pii> > mmm;
        //  cout<<mid<<'\n';
        for (int i=0;i<n;i++)
        {
            int x=(a[i].fi&q);
            int y=(a[i].se&q);
            first=x;
            g[x].insert({y,2*i+1});
            g[y].insert({x,2*i});
            //  cout<<x<<" "<<y<<'\n';
            //     mmm[{x,y}].insert({2*i,2*i+1});
            //     mmm[{y,x}].insert({2*i+1,2*i});
        }
        for (int i=0;i<(1<<mid);i++)
        {
            if (g[i].size()%2==1)
            {
                ok=false;
                break;
            }
        }
        if (!ok)
        {
            r=mid-1;
            continue;
        }
        stack<pair <int,pii>  > st;
        st.push ({first,{0,0}});
        vector<pii> res;
        while (!st.empty())
        {
            int v = st.top().fi;
            if (g[v].size()==0){
                res.push_back (st.top().se);
                st.pop();
            }
            else
            {
                auto to=g[v].begin();
                int i=(*to).fi;
                int y=(*to).se;
                st.push({i,{(y^1),y}});
                g[v].erase(to);
                g[i].erase({v,(y^1)});
            }
        }
        for (int i=0;i<(1<<mid);i++)
        {
            if (g[i].size()>0)
            {
                ok=false;
                break;
            }
        }
        if (!ok)
        {
            r=mid-1;
            continue;
        }
        ans=mid;
        vector <int> anss;
        for (int i=0;i<(int)(res.size())-1;i++)
            anss.pb(res[i].se),anss.pb(res[i].fi);
        ha=anss;
        l=mid+1;
    }
    cout<<ans<<'\n';
    for (auto to:ha)
        cout<<to+1<<" ";
    //n=1 ?
    //recursion - matrix exponential
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
}