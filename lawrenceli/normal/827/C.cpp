#include <bits/stdc++.h>

using namespace std;

int conv[200];

const int maxn = 100005;

int n, q;
int bit[11][10][4][maxn];

void upd(int a, int b, int c, int i, int v) {
    for (i++; i < maxn; i += i & -i) bit[a][b][c][i] += v;
}

int qry(int a, int b, int c, int i) {
    int ret = 0;
    for (i++; i > 0; i -= i & -i) ret += bit[a][b][c][i];
    return ret;
}

int main() {
    conv['A'] = 0, conv['T'] = 1, conv['G'] = 2, conv['C'] = 3;

    ios_base::sync_with_stdio(0);
    string s; cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
        int x = conv[s[i]];
        for (int k = 1; k <= 10; k++)
            upd(k, i % k, x, i, 1);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            int p; char c;
            cin >> p >> c;
            p--;
            int x = conv[s[p]];
            int y = conv[c];
            for (int k = 1; k <= 10; k++) {
                upd(k, p % k, x, p, -1);
                upd(k, p % k, y, p, 1);
            }
            s[p] = c;
        } else {
            int l, r;
            string e;
            cin >> l >> r >> e;
            l--;
            int k = e.length();
            int ans = 0;
            for (int p = l; p < l + k; p++) {
                int x = conv[e[p - l]];
                ans += qry(k, p % k, x, r - 1) - qry(k, p % k, x, l - 1);
            }
            cout << ans << '\n';
        }
    }
}