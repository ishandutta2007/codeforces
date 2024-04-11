#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100100;

int n, A, cf, cm, a[maxn];
pii ar[maxn];
ll m, pre[maxn], suf[maxn];
int vans[maxn];

int main() {
    ios_base::sync_with_stdio(0);


    cin >> n >> A >> cf >> cm >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ar[i] = pii(a[i], i);
    }
    sort(a, a + n);
    sort(ar, ar + n);

    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i];
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    ll ans = -1;
    int nf, nm;
    for (int i = 0; i <= n; i++) {
        ll m2 = m - (ll(i) * A - suf[n - i]);
        if (m2 < 0) continue;
        int lo = 0, hi = A;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            int lb = lower_bound(a, a + n - i, mid) - a;
            if (ll(mid) * lb - pre[lb] <= m2) lo = mid;
            else hi = mid - 1;
        }

        ll res = ll(cf) * i + ll(cm) * lo;
        if (ans < res) {
            ans = res;
            nf = i, nm = lo;
        }
    }

    cout << ans << '\n';
    for (int i = n - nf; i < n; i++)
        vans[ar[i].B] = A;
    int lb = lower_bound(a, a + n - nf, nm) - a;
    for (int i = 0; i < lb; i++) vans[ar[i].B] = nm;
    for (int i = lb; i < n - nf; i++) vans[ar[i].B] = a[i];
    for (int i = 0; i < n; i++) cout << vans[i] << ' ';
}