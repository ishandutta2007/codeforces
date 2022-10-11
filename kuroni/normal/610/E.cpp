#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int K = 10, N = 2E5 + 5;

int n, m, k, l, r, t, sim = 0, pos[K], cnt[K][K];
char c, s[N];
set<pair<int, int>> se;

void update(int l, int r, int v) {
    if (l == -1 || r == -1) {
        return;
    }
    cnt[l][r] += v;
    sim -= v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> (s + 1);
    se.insert({1, s[1] - 'a'});
    sim = n - 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            update(s[i - 1] - 'a', s[i] - 'a', 1);
            se.insert({i, s[i] - 'a'});
        }
    }
    while (m--) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r >> c;
            int st = -1, en = -1, lst = -1;
            auto it = se.lower_bound({l, 0});
            if (it != se.begin()) {
                st = lst = prev(it)->se;
            }
            for (; it != se.end() && it->fi <= r; it = se.erase(it)) {
                update(lst, it->se, -1);
                lst = it->se;
            }

            int pos = (it == se.end() ? n + 1 : it->fi);
            if (pos == r + 1) {
                if (pos != n + 1) {
                    update(lst, it->se, -1);
                }
            } else if (lst != -1) {
                it = se.insert({r + 1, lst}).fi;
            }
            if (it != se.end()) {
                en = it->se;
            }

            if (en != c - 'a') {
                update(c - 'a', en, 1);
            } else {
                se.erase(it);
            }
            if (st != c - 'a') {
                update(st, c - 'a', 1);
                se.insert({l, c - 'a'});
            }
        } else {
            cin >> s;
            for (int i = 0; i < k; i++) {
                pos[s[i] - 'a'] = i;
            }
            int ans = sim * k + pos[se.begin()->se];
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    ans += cnt[i][j] * ((pos[j] - pos[i] + k) % k);
                }
            }
            cout << ans / k + 1 << '\n';
        }
    }
}