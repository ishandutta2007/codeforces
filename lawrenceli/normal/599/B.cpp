#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100100;

int n, m, f[maxn], b[maxn], a[maxn], g[maxn];

int main() {
    cin >> n >> m;
    memset(g, -1, sizeof(g));
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        if (g[f[i]] == -1) g[f[i]] = i;
        else g[f[i]] = -2;
    }

    bool amb = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (g[b[i]] == -1) {
            cout << "Impossible\n";
            return 0;
        } else if (g[b[i]] == -2) amb = 1;
        else a[i] = g[b[i]];
    }

    if (amb) {
        cout << "Ambiguity\n";
        return 0;
    }
    
    cout << "Possible\n";
    for (int i = 0; i < m; i++)
        cout << a[i]+1 << ' ';
    cout << '\n';
}