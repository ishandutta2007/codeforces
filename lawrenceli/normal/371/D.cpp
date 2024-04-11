#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 200100;

int n, a[MAXN], par[MAXN], m, am[MAXN];

int getpar(int a) { par[a] == a ? a : par[a] = getpar(par[a]); }

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<=n; i++) par[i] = i;

    cin >> m;
    for (int i=0; i<m; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            int p, x; cin >> p >> x; p--;
            while (p != n) {
                if (x < a[p] - am[p]) {
                    am[p] += x;
                    break;
                } else {
                    x -= (a[p] - am[p]);
                    am[p] = a[p];
                    par[p] = p+1;
                    p = getpar(p);
                }
            }
        } else {
            int k; cin >> k; k--;
            cout << am[k] << endl;
        }
    }

    return 0;
}