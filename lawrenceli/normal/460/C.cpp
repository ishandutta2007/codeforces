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

const int MAXN = 200100;

int n, m, w, a[MAXN], bit[MAXN];

void update(int i, int v) {
    for (i++; i<MAXN; i+=i&-i) bit[i] += v;
}

int query(int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

bool check(int x) {
    memset(bit, 0, sizeof(bit));
    int cnt = 0;
    rep(i, n) {
        int b = a[i]+query(i);
        if (b >= x) continue;
        cnt += x-b;
        if (cnt > m) return 0;
        update(i, x-b);
        update(i+w, b-x);
    }
    return cnt <= m;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> w;
    rep(i, n) cin >> a[i];
    int lo = 1, hi = 1e9+1e5;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (check(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo << '\n';
    return 0;
}