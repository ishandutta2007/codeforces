#include <bits/stdc++.h>

using namespace std;

int n;
bitset <360> f;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    f.set(0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bitset <360> g = 0;
        for (int j = 0; j < 360; ++j) if (f.test(j)) g.set((j + x) % 360);
        for (int j = 0; j < 360; ++j) if (f.test(j)) g.set((j - x + 360) % 360);
        f = g;
    }
    cout << (f.test(0) ? "YES" : "NO") << endl;
    return 0;
}