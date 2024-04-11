#include <bits/stdc++.h>

using namespace std;

int n, k, a, b, q;
int l[200005], r[200005];
int tl[200005], tr[200005];

void upd(int *t, int pos, int val) {
    for (; pos <= n; pos += pos & -pos) t[pos] += val;
}

int get(int *t, int pos) {
    int ret = 0;
    for (; pos; pos -= pos & -pos) ret += t[pos];
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> a >> b >> q;
    int sum = 0;
    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) {
            int pos, val; cin >> pos >> val;
            int new_l = min(b, l[pos] + val);
            int new_r = min(a, r[pos] + val);
            sum += new_r - r[pos];
            upd(tl, pos, new_l - l[pos]);
            upd(tr, pos, new_r - r[pos]);
            l[pos] = new_l; r[pos] = new_r;
        }
        else {
            int pos; cin >> pos;
            cout << get(tl, pos - 1) + (sum - get(tr, pos + k - 1)) << '\n';
        }
    }
}