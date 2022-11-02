#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 100 * 1000 + 10;

pli a[N];
ll sum[N]; 
ll ans[N];
ll A, cf, cm;
ll units;
int n;

ll getSum(int l, int r) {
    if (l > r)
        return 0;
    ll res = sum[r];
    if (l > 0)
        res -= sum[l - 1];
    return res;
}

ll calc(int perf) {
    ll cur = units;
    ll mid = n - perf;
    cur -= A * perf - getSum(mid, n - 1);
    if (cur < 0)
        return -1;
    if (mid == 0)  
        return perf * cf + A * cm;
    ll lo = a[0].first;
    ll hi = A + 1;
    while (hi - lo > 1) {
        ll m = (lo + hi) / 2;
        int bigPos = lower_bound(a, a + mid, pli(m, -1)) - a;
        ll delta = m * bigPos - getSum(0, bigPos - 1);
        if (delta <= cur)
            lo = m;
        else
            hi = m;
    } 
    return perf * cf + lo * cm;
}

void rec(int perf) {
    ll cur = units;
    ll mid = n - perf;
    cur -= A * perf - getSum(mid, n - 1);
    ll lo = a[0].first;
    ll hi = A + 1;
    if (mid > 0) {
        while (hi - lo > 1) {
            ll m = (lo + hi) / 2;
            int bigPos = lower_bound(a, a + mid, pli(m, -1)) - a;
            ll delta = m * bigPos - getSum(0, bigPos - 1);
            if (delta <= cur)
                lo = m;
            else
                hi = m;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i >= mid)   
            ans[a[i].second] = A;
        else
            ans[a[i].second] = max(lo, a[i].first);
    }   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> A >> cf >> cm >> units;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        sum[i] = a[i].first;
        if (i > 0)
            sum[i] += sum[i - 1];
    }
    ll best = -1;
    int bestP = 0;
    for (int p = 0; p <= n; p++) {
        ll score = calc(p);
        if (score > best) {
            best = score;
            bestP = p;
        }
    }
    cout << best << endl;
    rec(bestP);         
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;    
    return 0;
}