#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_v = 2000111, inf = 1000111222;

ll a[max_n];
ll b[max_n];
ll m[max_n];
ll d[max_n];
ll sum[max_n];
int n, q;
bool debug = 0;

ll ans[max_v];
ll dss[max_v];
ll ds[max_v];


void add_pr(int from, int to, int step, int base) {
    /*int cur = base;
    for (int i = from ; i <= to; ++i) {
        ans[i] += cur;
        cur += step;
    }*/
    base -= step;
    ds[from] += base;
    ds[to + 1] -= base;
    ds[to + 1] -= (step * (to - from + 1));
    dss[from] += step;
    dss[to + 1] -= step;
}

void apply() {
    //return;
    ll step = 0;
    ll step2 = 0;
    for (int i = 0; i < max_v; ++i) {
        step2 += dss[i];
        step += step2;
        step += ds[i];
        ans[i] += step;
    }
}

void proc(ll base, ll d) {
    //ans[i] += abs(base + d * i);
    //cout << "$$ " << base << ' ' << d << endl;
    if (base < 0) {
        base *= -1;
        d *= -1;
    }
    if (d >= 0) {
        add_pr(0, max_v - 2, d, base);
    } else {
        int k = base / abs(d);
        add_pr(0, min(max_v - 3, k), d, base);
        int st = abs(base % d - d);
        if (k + 1 < max_v - 3)
        add_pr(k + 1, max_v - 3, abs(d), st);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i <= n; ++i) {
        sum[i] = 1;
    }
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        d[i] = -sum[i];
        for (int j = i; j <= n; j += i) {
            sum[j] += d[i];
        }
    }
    cin >> q;
    int mn = 1e8;
    vector<int> v;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        v.PB(x);
        mn = min(mn, x);
    }
    //sort(v.begin(), v.end());
    b[1] = mn;

    for (int i = 1; i <= n; ++i) {
        //cout << "$$ " << b[i] << ' ' << a[i] << endl;
        m[i] = b[i] - a[i];
        for (int j = i; j <= n; j += i) {
            a[j] += m[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        d[i] = d[i + 1];
        if (debug) cout << d[i] << ' ';
    }
    if (debug) cout << endl;
    for (int i = 0; i < n; ++i) {
        m[i] = m[i + 1];
        if (debug) cout << m[i] << ' ';
    }
    if (debug) cout << endl;
    for (int i = 0; i < n; ++i) {
        proc(m[i], d[i]);
    }
    apply();
    for (int x : v) {
        cout << ans[x - mn] << "\n";
    }
    return 0;
}