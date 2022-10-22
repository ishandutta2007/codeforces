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

const int LOG = 30;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<vector<int>> q[LOG + 1];

    vector<int> perm(n);
    for (int i = 1; i <= n; i++)
        perm[i - 1] = i;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    q[LOG].push_back(perm);

    ll inv = 0, x = 0;
    for (int bit = LOG; bit >= 0; bit--) {
        ll total1 = 0;
        ll total2 = 0;
        for (auto seq : q[bit]) {
            if (seq.empty())
                continue;
            vector<int> t0, t1;
            for (int id : seq)
                if ((1 << bit) & a[id])
                    t1.push_back(id);
                else
                    t0.push_back(id);

            ll hlp1 = 0;
            ll hlp2 = 0;

            for (int j = 0, i = 0; i < (int) t0.size(); i++) {
                while (j < (int) t1.size() && t1[j] < t0[i])
                    j++;
                hlp1 += j;
            }

            for (int j = 0, i = 0; i < (int) t1.size(); i++) {
                while (j < (int) t0.size() && t0[j] < t1[i])
                    j++;
                hlp2 += j;
            }

            total1 += hlp1;
            total2 += hlp2;

            if (bit > 0) {
                q[bit - 1].push_back(t0);
                q[bit - 1].push_back(t1);
            }
        }

        if (total2 < total1) {
            inv += total2;
            x |= (1ll << bit);
        } else {
            inv += total1;
        }
    }

    cout << inv << " " << x << "\n";

    return 0;
}