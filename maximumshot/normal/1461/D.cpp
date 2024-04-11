#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<int> fast(int n, int q, vector<int> a, vector<int> b) {
    sort(a.begin() + 1, a.end());
    unordered_set<ll> Q;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i];
    function<void(int, int, ll)> rec = [&](int l, int r, ll S) {
        Q.insert(S);
        ll x = (a[l] + a[r]) / 2;
        int ql = l, qr = r, sep;
        if (a[r] <= x || a[l] > x)
            return;
        while (1) {
            if (a[ql] <= x && a[ql + 1] > x) {
                sep = ql;
                break;
            }
            if (a[qr] > x && a[qr - 1] <= x) {
                sep = qr - 1;
                break;
            }
            ql++, qr--;
        }
        if (sep - l + 1 < r - sep) {
            ll hlp = 0;
            for (int i = l; i <= sep; i++)
                hlp += a[i];
            rec(l, sep, hlp);
            rec(sep + 1, r, S - hlp);
        } else {
            ll hlp = 0;
            for (int i = sep + 1; i <= r; i++)
                hlp += a[i];
            rec(l, sep, S - hlp);
            rec(sep + 1, r, hlp);
        }
    };
    rec(1, n, sum);
    vector<int> res(q);
    for (int i = 0; i < q; i++)
        res[i] = Q.count(b[i]);
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> b(q);
        for (int i = 0; i < q; i++)
            cin >> b[i];
        vector<int> fs = fast(n, q, a, b);
        for (int x : fs)
            cout << (x ? "Yes" : "No") << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}