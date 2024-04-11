#include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
char a[maxN][maxN][4];
int t[4];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int best = 100 * 100 * 4;
    for (int i = 0; i < 4; i++) t[i] = i;
    cin >> n;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> a[j][k][i];
            }
        }
    }
    do {
        //for (int i = 0; i < 4; i++) cout << t[i] << " ";
        //cout << endl;
        int cur = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if ((t[i] + k + j) & 1) {
                        if (a[j][k][i] == '1') cur++;
                    }
                    else {
                        if (a[j][k][i] == '0') cur++;
                    }
                }
            }
        }
        best = min(best, cur);
    } while (next_permutation(t, t + 4));
    cout << best;
    return 0;
}