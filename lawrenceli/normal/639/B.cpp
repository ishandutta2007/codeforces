#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int N, D, H;

int main() {
    cin >> N >> D >> H;
    if (D > 2 * H) {
        cout << "-1\n";
        return 0;
    }

    if (N > 2 && D == 1 && H == 1) {
        cout << "-1\n";
        return 0;
    }
    
    int cnt = 2;
    for (int i = 0; i < H; i++) {
        cout << cnt - 1 << ' ' << cnt << '\n';
        cnt++;
    }

    for (int i = 0; i < D - H; i++) {
        if (!i) cout << 1 << ' ' << cnt << '\n';
        else cout << cnt - 1 << ' ' << cnt << '\n';
        cnt++;
    }

    while (cnt <= N) {
        if (H == 1) cout << 1 << ' ' << cnt << '\n';
        else cout << 2 << ' ' << cnt << '\n';
        cnt++;
    }
}