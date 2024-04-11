#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
#define MAXC 100

int n, m, maxc = -1;
bool con[MAXC][MAXN][MAXN];

int q1[MAXN], q1n, q2[MAXN], q2n;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;

        maxc = max(maxc, c);

        q1[0] = a;
        q2[0] = b;
        q1n = q2n = 1;
        for (int j = 0; j < n; j++) {
            if (con[c][a][j]) q1[q1n++] = j;
            if (con[c][b][j]) q2[q2n++] = j;
        }
        for (int j = 0; j < q1n; j++) {
            for (int k = 0; k < q2n; k++) {
                con[c][q1[j]][q2[k]] = con[c][q2[k]][q1[j]] = true;
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int s = 0;
        for (int j = 0; j <= maxc; j++) {
            if (con[j][a][b]) {
                cerr << a << " -> " << b << " with " << j << endl;
                s++;
            }
        }
        cout << s << endl;
    }
    return 0;
}