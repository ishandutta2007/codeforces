#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

struct Fenwick {
    vector<ll> f;
    int n;

    Fenwick(int _n) {
        n = _n;
        f.resize(_n + 1);
    }

    void upd(int pos, int v) {
        while (pos <= n) {
            f[pos] += v;
            pos = (pos | (pos - 1)) + 1;
        }
    }

    ll get(int r) {
        ll ans = 0;
        while (r > 0) {
            ans += f[r];
            r &= (r - 1);
        }
        return ans;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int lst = -k - 15;
        int ch = 0;
        vector < int > nxt(n + 1);
        nxt[n] = n + k + 10;
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            if (s[i] == '1') nxt[i] = i;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (i - lst > k && nxt[i] - i > k) {
                    lst = i;
                    ch++;
                }
            }
            else {
                lst = i;
            }
        }
        cout << ch << '\n';
    }
    return 0;
}