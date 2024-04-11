#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <ios>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef long double ld;
typedef pair<ld, int> pii;

const int maxn = 1005;

int n, p[maxn][maxn];
bool v[maxn];
ld e[maxn], k[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];

    for (int i = 0; i < n - 1; i++) k[i] = e[i] = -1;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, n - 1));
    while (!pq.empty()) {
        ld d = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (v[x]) continue;
        v[x] = 1;

        for (int i = 0; i < n; i++)
            if (i != x && !v[i] && p[i][x]) {
                ld q = ld(p[i][x]) / 100;
                if (k[i] == -1) {
                    e[i] = 1. / q + d;
                    k[i] = 1. - q;
                } else {
                    e[i] = (1. - k[i]) * e[i] + k[i] * q * d;
                    k[i] *= 1. - q;
                    e[i] /= 1 - k[i];
                }
                pq.push(pii(e[i], i));
            }
    }

    cout << fixed << setprecision(10) << e[0] << '\n';
}