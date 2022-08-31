#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int le, ri;
pair < int, int > a[1005];
pair < int, int > b[1005];
int c[1005];
void add(int x) {
    if (x <= (q / 2)) {
        for (int i = 1; i <= n; i++) {
            if (c[i] > x || c[i] == 0) {
                if (c[i] == 0) le++;
                c[i] = x;
                cout << i << endl;
                break;
            }
        }
    }
    else {
        for (int i = n; i >= 1; i--) {
            if (c[i] < x) {
                if (c[i] == 0) ri++;
                c[i] = x;
                cout << i << endl;
                break;
            }
        }
    }
    if (le + ri == n) exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    ri = 0;
    le = 0;
    int x;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        add(x);
    }
    return 0;
}