#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>
#include <cassert>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;

const int maxn = 2105;
const int inf = 1e9;

int n, m;
string s, t;
int D[maxn][maxn][2];
pii P[maxn][maxn][2];
pii K[maxn]; int KS;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> t >> s;
    n = s.length(), m = t.length();

    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            for (int k = 0; k < 2; k++)
                D[i][j][k] = inf;

    D[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        int mi = inf, j1, k1;
        
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 2; k++) {
                if (D[i][j][k] < mi)
                    mi = D[i][j][k], j1 = j, k1 = k;

                if (!i) continue;
                int d = k ? 1 : -1;
                if (j + d >= 0 && j + d < m && t[j + d] == s[i]) {
                    if (D[i + 1][j + d][k] > D[i][j][k])
                        D[i + 1][j + d][k] = D[i][j][k], P[i + 1][j + d][k] = pii(j, k);
                }
            }

        if (mi == inf) continue;
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 2; k++)
                if (D[i + 1][j][k] > mi + 1 && t[j] == s[i])
                    D[i + 1][j][k] = mi + 1, P[i + 1][j][k] = pii(j1, k1);
    }

    int ans = inf, i = n, j, k;
    for (int j1 = 0; j1 < m; j1++)
        for (int k1 = 0; k1 < 2; k1++)
            if (ans > D[n][j1][k1])
                ans = D[n][j1][k1], j = j1, k = k1;

    if (ans == inf) {
        cout << "-1\n";
        return 0;
    }

    int cur = j;
    while (i) {
        int j1 = P[i][j][k].A, k1 = P[i][j][k].B;
        int b = D[i][j][k] - D[i - 1][j1][k1];
        if (b) {
            K[KS++] = pii(j, cur);
            cur = j1;
        }
        j = j1, k = k1, i--;
    }

    assert(KS == ans);
    reverse(K, K + KS);
    cout << KS << '\n';
    for (int i = 0; i < KS; i++)
        cout << K[i].A + 1 << ' ' << K[i].B + 1 << '\n';
}