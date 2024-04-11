#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int q, a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        int mi = min(a, min(b, c));
        a -= mi; b -= mi; c -= mi;
        cout << mi + min(min(a, b), (a + b) / 3) << '\n';
    }
}