#include <bits/stdc++.h>

using namespace std;

int n;
int ok[105];
int pk[105];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 100; ++i) ok[i] = 1;
    while (n--) {
        memset(pk, 0, sizeof pk);
        int r, x; cin >> r;
        while (r--) cin >> x, pk[x] = 1;
        for (int i = 1; i <= 100; ++i) ok[i] &= pk[i];
    }
    for (int i = 1; i <= 100; ++i) if (ok[i]) cout << i << ' '; cout << endl;
    return 0;
}