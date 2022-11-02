#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <ios>
#include <iomanip>

using namespace std;

const int maxn = 500100;
const int maxp = 40;

int n, q;
double d[maxn][maxp];
int p[maxn];

void upd(int v, int k, double x) {
    while (v && k < maxp) {
        double a = d[v][k];
        d[v][k] *= x;
        x = (d[v][k] + 1) / (a + 1);
        v = p[v];
        k++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxp; j++)
            d[i][j] = 1;

    cin >> q;
    n = 1;
    for (int i = 0; i < q; i++) {
        int qtype, v;
        cin >> qtype >> v;
        if (qtype == 1) {
            p[++n] = v;
            upd(n, 0, 0);
        } else {
            double ans = 0;
            for (int j = 1; j < maxp; j++)
                ans += (1 - d[v][j]);
            cout << fixed << setprecision(10) << ans << '\n';
        }
    }
}