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
const int MAXN = 1e5+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;

void solve()
{
    int n;
    cin>>n;
    vector <int> a;
    {
        vector <int> c(n);
        in(c);
        int i=0;
        while (i<n){
            int j=i;
            int cnt=0;
            while (j<n&&c[i]==c[j])
                cnt++,j++;
            a.pb(c[i]);
            i=j;
        }
    }
    multiset<int> s;
    for (int i=1;i<=n;i++)
        s.insert(INF);
    s.insert(0);
    vector <int> val(n+1,INF);
    val[0]=0;
    int add=0;
    int was=0;
    for (auto to:a)
    {
        int minx=(*s.begin())+add;
        s.erase(s.find(val[was]));
        int now_was=val[to]+add;
        s.insert(min(minx+1,now_was)-add-1);
        val[was]=min(minx+1,now_was)-add-1;
        add++;
        was=to;
//        for (auto too:val)
//            cout<<too+add<<" ";
//        cout<<'\n';
    }
    cout<<(*s.begin())+add<<'\n';
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
//    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}