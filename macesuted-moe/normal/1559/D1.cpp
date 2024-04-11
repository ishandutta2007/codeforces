#include <bits/stdc++.h>
using namespace std;

#define maxn 1005

typedef pair<int, int> pii;

int f[2][maxn];

int getfa(int t, int p) { return f[t][p] == p ? p : f[t][p] = getfa(t, f[t][p]); }

int main() {
    ios::sync_with_stdio(false);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (register int i = 1; i <= n; i++) f[0][i] = f[1][i] = i;
    for (register int i = 1; i <= m1; i++) {
        int x, y;
        cin >> x >> y;
        x = getfa(0, x), y = getfa(0, y);
        f[0][x] = y;
    }
    for (register int i = 1; i <= m2; i++) {
        int x, y;
        cin >> x >> y;
        x = getfa(1, x), y = getfa(1, y);
        f[1][x] = y;
    }
    static vector<pii> cache;
    cache.clear();
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= n; j++)
            if (i != j && getfa(0, i) != getfa(0, j) && getfa(1, i) != getfa(1, j)) {
                f[0][getfa(0, i)] = getfa(0, j);
                f[1][getfa(1, i)] = getfa(1, j);
                cache.push_back((pii){i, j});
            }
    cout << cache.size() << endl;
    for (vector<pii>::iterator i = cache.begin(); i != cache.end(); i++) cout << i->first << ' ' << i->second << endl;
    return 0;
}