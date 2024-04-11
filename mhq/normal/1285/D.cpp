#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
struct node{
    int nxt[2];
    node() {
        nxt[0] = nxt[1] = -1;
    }
};
const int maxN = (int)1e5 + 10;
node t[30 * maxN * 2];
int sz = 1;
void add(int v) {
    int cur = 1;
    for (int i = 29; i >= 0; i--) {
        int bt = (v >> i) & 1;
        if (t[cur].nxt[bt] == -1) {
            t[cur].nxt[bt] = ++sz;
        }
        cur = t[cur].nxt[bt];
    }
}
int get(int v, int bit) {
    if (v == -1) return 0;
    if (t[v].nxt[0] == -1) return get(t[v].nxt[1], bit - 1);
    if (t[v].nxt[1] == -1) return get(t[v].nxt[0], bit - 1);
    return (1 << bit) + min(get(t[v].nxt[0], bit - 1), get(t[v].nxt[1], bit - 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(x);
    }
    cout << get(1, 29);
    return 0;
}