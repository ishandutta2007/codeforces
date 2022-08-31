#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = (int)1e9 + 10;
int n, q;
const int maxN = 2 * (int)1e5 + 10;
int a[maxN];
vector < int > vals[maxN];
int t[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = min(t[v + v], t[v + v + 1]);
}
int get_mn(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get_mn(v + v, tl, tm, l, r);
    else if (l > tm) return get_mn(v + v + 1, tm + 1, tr, l, r);
    else return min(get_mn(v + v, tl, tm, l, tm), get_mn(v + v + 1, tm + 1, tr, tm + 1, r));
}
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    cin >> n >> q;
    bool zero = false;
    bool if_q = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) zero = true;
        if_q |= (a[i] == q);
    }
    if (!zero && !if_q) {
        cout << "NO";
        return 0;
    }
    int cur = q;
    if (if_q == true) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) {
                cur = a[i];
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) {
            cur = a[i];
        }
        else {
            if (!if_q) {
                a[i] = q;
                if_q = true;
            }
            else {
                a[i] = cur;
            }
        }
    }
    for (int i = 1; i <= n; i++) vals[a[i]].push_back(i);
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        if (vals[i].empty()) continue;
        int l = vals[i][0] + 1;
        int r = vals[i].back() - 1;
        if (l > r) continue;
        if (get_mn(1, 1, n, l, r) < i) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    // 2 1 2 - bad
    // a ... a
    //
    return 0;
}