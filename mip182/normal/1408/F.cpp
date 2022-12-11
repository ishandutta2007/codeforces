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
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1 = 1e9+7;
const ll mod2 = 2e9+11;
vector <pii> ans;
void solve()
{
    int n;
    cin>>n;
    vector <vector <int> > a(n);
    for (int i=0;i<n;i++)
    {
        vector <int> x={i+1};
        a[i]=x;
    }
    auto merge = [&](vi &x,vi &y)
    {
        for (int i=0;i<x.size();i++)
            ans.pb({x[i],y[i]});
        for (auto to:y)
            x.pb(to);
        y.clear();
    };
    auto add = [&](vi &x,vi &y)
    {
        int cnt=0;
        int szz=y.size();
        while (cnt!=szz)
        {
            ans.pb({x.back(),y[cnt++]});
            y.pb(x.back());
            x.pop_back();
        }
    };
    auto split_merge=[&](vi &x,vi &y,vi &z,int sz1,int sz2,int big)
    {
        vector <int> fir,sec;
        for (int i=0;i<sz1;i++)
        {
            ans.pb(mp(x.back(),y.back()));
            fir.pb(x.back());
            fir.pb(y.back());
            x.pop_back();
            y.pop_back();
        }
        for (int i=0;i<sz1;i++)
        {
            ans.pb(mp(y.back(),z.back()));
            sec.pb(y.back());
            sec.pb(z.back());
            z.pop_back();
            y.pop_back();
        }
        for (int i=0;i<sz2;i++)
        {
            ans.pb(mp(fir.back(),sec.back()));
            x.pb(sec.back());
            x.pb(fir.back());
            sec.pop_back();
            fir.pop_back();
        }
    };
    while (true)
    {
        sort(rall(a),[&](vi &x,vi &y){return x.size()<y.size();});
//        for (auto &to:a)
//            cout<<to.size()<<" ";
//        cout<<'\n';
        while (a[(int)(a.size())-1].size()==0)
            a.pop_back();
        if (a.size()<=2)
            break;
        bool ok=false;
        for (int i=0;i<(int)a.size()-1;i++)
        {
            if (a[i].size()==a[i+1].size())
            {
                merge(a[i],a[i+1]);
                i++;
                ok=true;
                continue;
            }
        }
        if (ok)
            continue;
        n=a.size();
        int sz1=a[n-1].size();
        int sz2=a[n-2].size();
        int big=a[0].size();
        if (sz1*2==sz2)
        {
            split_merge(a[n-1],a[n-2],a[0],sz1,sz2,big);
        }
        else
        {
            add(a[0],a[n-1]);
        }
    }
    cout<<ans.size()<<'\n';
    for (auto to:ans)
        cout<<to.fi<<" "<<to.se<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef Mip182
    freopen("a.in", "r", stdin);
#endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}