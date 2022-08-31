#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5 * (int)1e5 + 100;
int p[maxN];
int sz[maxN];
int get(int a) {
    if (a == p[a]) return a;
    p[a] = get(p[a]);
    return p[a];
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    p[a] = b;
    return ;
}
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        int prv = -1;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            if (prv != -1) {
                unite(prv, x);
            }
            prv = x;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << sz[get(i)] << " ";
    }
    return 0;
}