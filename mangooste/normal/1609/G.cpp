#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    for (auto &x : a)
        cin >> x;

    for (auto &x : b)
        cin >> x;

    vector<ll> da(n - 1), db(m - 1);
    for (int i = 0; i < n - 1; i++)
        da[i] = a[i + 1] - a[i];

    for (int i = 0; i < m - 1; i++)
        db[i] = b[i + 1] - b[i];

    const int nblocks = (m + 254) >> 8;
    vector<ll> dec(nblocks);

    struct binary_index_tree {
        int n;
        vector<ll> bit;

        binary_index_tree(int n) : n(n), bit(n + 1) {}

        void add(int pos, ll value) {
            for (pos++; pos <= n; pos += pos & -pos)
                bit[pos] += value;
        }

        ll query(int pref) {
            ll tot = 0;
            for (; pref; pref -= pref & -pref)
                tot += bit[pref];

            return tot;
        }
    } bit1(m - 1), bit2(m - 1);

    ll to_add = 0;
    for (int i = 0; i < m - 1; i++)
        to_add += db[i] * (m - 1 - i);

    vector<ll> pref(m);
    for (int i = 0; i < m - 1; i++)
        pref[i + 1] = pref[i] + db[i];

    while (q--) {
        int type, k, d;
        cin >> type >> k >> d;

        if (type == 1) {
            if (k == n) {
                k--;
                a[0] += d;
            }

            for (int i = n - 1 - k; i < n - 1; i++)
                da[i] += d;
        } else if (type == 2) {
            if (k == m) {
                k--;
                b[0] += d;
            }

            to_add += 1ll * d * k * (k + 1) / 2;
            k = m - k - 1;

            bit1.add(k, d);
            bit2.add(k, 1ll * d * k);

            for (; k < m - 1 && (k & 255); k++)
                db[k] += d;

            for (; k < m - 1; k += 256)
                dec[k >> 8] += d;
        } else {
            assert(false);
        }

        ll answer = (a[0] + b[0]) * (n + m - 1) + to_add;
        for (int i = 0; i < n - 1; i++) {
            int l = -1, r = m - 1;
            while (r - l > 1) {
                int mid = (l + r) >> 1;
                (db[mid] + dec[mid >> 8] > da[i] ? r : l) = mid;
            }

            answer += r * bit1.query(r) - bit2.query(r);
            answer += pref[r];
            answer += da[i] * ((m - 1 - r) + (n - 1 - i));
        }

        cout << answer << '\n';
    }
}