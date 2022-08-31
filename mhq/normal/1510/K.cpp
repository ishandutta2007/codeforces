#include <bits/stdc++.h>

using namespace std;

int n;
const int maxN = 2005;
int p[maxN];
int q[maxN];
bool ok() {
    for (int i = 0; i < 2 * n; i++) {
        if (q[i] != i) return false;
    }
    return true;
}
void apply(int v) {
    if (v == 0) {
        for (int i = 0; i < 2 * n; i += 2) {
            swap(q[i], q[i + 1]);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            swap(q[i], q[i + n]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> p[i];
        --p[i];
    }
    int best = 1e9;
    for (int start = 0; start < 2; start++) {
        for (int i = 0; i < 2 * n; i++) {
            q[i] = p[i];
        }
        for (int c = 0; c < 4 * n + 10; c++) {
            if (ok()) {
                best = min(best, c);
                break;
            }
            apply((c + start) % 2);
        }
    }
    if (best > 1e8) best = -1;
    cout << best;
    return 0;
}