#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, c, q;
char s[nax];
int64_t l[nax], r[nax];
int64_t slen[nax];


char trace(int cur_c, int64_t k) {
    //cout << "trace " << cur_c << ' ' << k << '\n';
    if (cur_c == 0) {
        return s[k];
    }
    if (k > slen[cur_c - 1] && k <= slen[cur_c]) {
        int64_t dif = k - slen[cur_c - 1];
        return trace(cur_c - 1, l[cur_c] + dif - 1);
    }
    return trace(cur_c - 1, k);
}

void solve() {
    cin >> n >> c >> q;
    cin >> s + 1;
    slen[0] = n;
    for (int i = 1 ; i <= c ; ++ i) {
        cin >> l[i] >> r[i];
        slen[i] = slen[i - 1] + (r[i] - l[i] + 1);
    }

    while (q --) {
        int64_t k;
        cin >> k;
        cout << trace(c, k) << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}