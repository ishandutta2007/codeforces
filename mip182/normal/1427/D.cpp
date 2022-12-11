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
const int mod1 = 1e9+7;
const int mod2 = 2e9+11;
void does(vector <int> &a,vector <int> &q)
{
    vector <vector <int> > f;
    int i=0;
    int cur=0;
    while (true)
    {
        if (cur==q.size())
            break;
        int cnt=0;
        vector <int> now;
        while (true)
        {
            now.pb(a[i]);
            i++;
            cnt++;
            if (cnt==q[cur])
                break;
        }
        cur++;
        f.pb(now);
    }
    reverse(all(f));
    a.clear();
    for (auto &to:f)
    {
        for (auto too:to)
            a.pb(too);
    }
}
void solve()
{
    int n;
    cin>>n;
    vector <int> a(n);
    rep(i,n)
        cin>>a[i],a[i]--;
    if (n==1)
    {
        cout<<0<<'\n';
        return;
    }
    vector <vector <int> > ans;
    bool ok=false;
    for (int i=0;i<n-1;i++)
    {
        vector <int> d;
        if (!ok) {
            for (int f=0;f<i;f++)
                d.pb(1);
            int cnt=0;
            for (int j = i; j < n; j++) {
                cnt++;
                if (a[j] == i) {
                    break;
                }
            }
            d.pb(cnt);
            if (i+cnt != n)
                d.pb(n - (i+cnt));
        }
        else
        {
            for (int f=0;f<i;f++)
                d.pb(1);
            int cnt=0;
            for (int j = n-1-i; j >=0; j--) {
                cnt++;
                if (a[j] == i) {
                    break;
                }
            }
            d.pb(cnt);
            if (i+cnt != n)
                d.pb(n - (i+cnt));
            reverse(all(d));
        }
        if (d.size()>1)
        ans.pb(d);
        does(a,d);
        ok=!ok;
    }
    if (ok)
    {
        vector <int> d;
        for (int i=0;i<n;i++)
            d.pb(1);
        ans.pb(d);
    }
    cout<<ans.size()<<'\n';
    for (auto &to:ans)
    {
        cout<<to.size()<<" ";
        for (auto too:to)
            cout<<too<<" ";
        cout<<'\n';
    }
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