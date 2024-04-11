#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 1000100;

int n, ar[MAXN], num[MAXN];
map<int, int> freq;
int bit[MAXN];
ll ans;

void update(int i, int v) {
    for (i++; i<MAXN; i+=i&-i) bit[i] += v;
}

int query(int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) cin >> ar[i];
    for (int i=n-1; i>=0; i--) num[i] = ++freq[ar[i]], update(num[i], 1);
    freq.clear();
    rep(i, n) update(num[i], -1), ans += query(freq[ar[i]]++);
    cout << ans << '\n';
    return 0;
}