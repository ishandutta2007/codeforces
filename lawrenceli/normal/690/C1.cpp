#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int n, m;
int par[maxn];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) { par[getpar(a)] = getpar(b); }

int main() {
    cin >> n >> m;
    if (m != n - 1) {
        cout << "no\n";
        return 0;
    }

    iota(par, par + n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    for (int i = 1; i < n; i++)
        if (getpar(i) != getpar(i + 1)) {
            cout << "no\n";
            return 0;
        }
    cout << "yes\n";
}