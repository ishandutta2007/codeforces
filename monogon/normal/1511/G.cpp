
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int K = 9, LG = 18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi cnt(m + 2, 0), pref(m + 2, 0);
    rep(i, 0, n) {
        int c;
        cin >> c;
        cnt[c]++;
    }
    rep(i, 1, m + 2) pref[i] = pref[i - 1] + cnt[i];
    vector<bitset<1 << K>> mask(m + 2);
    for(int i = m; i >= 1; i--) {
        mask[i] = (mask[i + 1] << 1);
        mask[i][0] = mask[i + 1][(1 << K) - 1] ^ (cnt[i] % 2 == 1);
    }

    auto get = [&](int l, int r) {
        return pref[r] - pref[l - 1];
    };

    int q;
    cin >> q;
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        bool flag = true;
        for(int d = (1 << K); d < (1 << LG); d <<= 1) {
            bool b = false;
            for(int i = d; l + i <= r; i += 2 * d) {
                if(get(l + i, min(r, l + i + d - 1)) % 2 == 1) b = !b;
            }
            if(b) {
                flag = false;
                break;
            }
        }
        int x = 0;
        int dif = ((l - r - 1) % (1 << K) + (1 << K)) % (1 << K);
        rep(i, 0, 1 << K) {
            if(mask[l][i]) x ^= i;
            if(mask[r + 1][(i + dif) % (1 << K)]) x ^= i;
        }

        if(x == 0 && flag) {
            cout << 'B';
        }else {
            cout << 'A';
        }
    }
    cout << '\n';
}