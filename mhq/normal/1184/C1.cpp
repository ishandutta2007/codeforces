#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 55;
int x[maxN], y[maxN];
int n;
set < int > xx;
set < int > yy;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    n = 4 * n + 1;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        xx.insert(x[i]);
        yy.insert(y[i]);
    }
    for (int x1 : xx) {
        for (int x2 : xx) {
            if (x1 >= x2) continue;
            for (int y1 : yy) {
                for (int y2 : yy) {
                    if (y1 >= y2) continue;
                    int who = -1;
                    bool ok = true;
                    for (int i = 1; i <= n; i++) {
                        if (x[i] < x1 || x[i] > x2 || y[i] < y1 || y[i] > y2) {
                            if (who != -1) {
                                ok = false;
                                break;
                            }
                            else {
                                who = i;
                            }
                        }
                        else if (x[i] != x1 && x[i] != x2 && y[i] != y1 && y[i] != y2) {
                            if (who != -1) {
                                ok = false;
                                break;
                            }
                            else {
                                who = i;
                            }
                        }
                    }
                    if (who == -1 || !ok) continue;
                    cout << x[who] << " " << y[who];
                    return 0;
                }
            }
        }
    }
    return 0;
}