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
const int mod1 = 1e9+21;
const int mod2 = 2e9+11;

void solve()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        iota(all(a),1);
        reverse(all(a));
        if (n&1)
            swap(a[n/2],a[n/2-1]);
        for (auto to:a)
            cout<<to<<" ";
        cout<<'\n';
    }
//    int a,b;
//    cin>>a>>b;
//    cout<<(a*b)/2<<'\n';
//    int i=-1,sqr3=-1;
//    for (int cur=1;cur<mod1;cur++)
//    {
//        if (1ll*cur*cur%mod1==mod1-1)
//        {
//            i=cur;
//            break;
//        }
//    }
//    cout<<i<<'\n';
//    for (int cur=1;cur<mod1;cur++)
//    {
//        if (1ll*cur*cur%mod1==3)
//        {
//            sqr3=cur;
//            break;
//        }
//    }
//    cout<<sqr3<<'\n';
}

int main() {
//#ifdef Mip182
//#else
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//#endif
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}