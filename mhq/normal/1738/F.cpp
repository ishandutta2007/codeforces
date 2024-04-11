#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1005;
int deg[maxN];
int n;
bool mark[maxN];
int clr[maxN];
int ask(int x) {
    cout << "? " << x << endl;
    int resp;
    cin >> resp;
    return resp;
}
int p[maxN];
int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rand() & 1) swap(a, b);
    p[b] = a;
    return true;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i];
    }
    memset(mark, 0, sizeof mark);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    while (true) {
        int x = -1;
        for (int i = 1; i <= n; i++) {
            if (!mark[i] && (x == -1 || deg[i] > deg[x])) x = i;
        }
        if (x == -1) break;
        mark[x] = true;
        for (int it = 0; it < deg[x]; it++) {
            int c = ask(x);
            unite(c, x);
            if (mark[c]) {
                break;
            }
            mark[c] = true;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << get(p[i]) << " ";
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}