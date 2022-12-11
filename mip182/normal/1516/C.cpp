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
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
const int K = 2000 * 100 / 2 + 1;

bool can_split(vector<int> &a) {
    int sum = accumulate(all(a), 0);
    if (sum & 1)
        return false;
    bitset<K> dp;
    dp[0] = true;
    for (auto to:a) {
        dp |= (dp << to);
    }
    return dp[sum / 2];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);in(a);
    if (!can_split(a)) {
//        cout<<"ahha\n";
        cout << 0 << '\n';
        return;
    }
    int ind = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1)
            ind = i;
    }
    if (ind != -1) {
        cout << 1 << '\n' << ind + 1 << '\n';
        return;
    }
    int mx=INF;
    int cur=0;
    for (auto to:a)
    {
        int cnt=0;
        while (to%2==0)
            cnt++,to/=2;
        if (mx>cnt)
            mx=cnt,ind=cur;
        cur++;
    }
    cout<<1<<'\n'<<ind+1<<'\n';
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
//    cin>>_t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}