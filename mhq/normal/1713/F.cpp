#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (1 << 19) + 20;
int b[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int bit = 0; bit < 19; bit++) {
        for (int i = 0; i < n; i++) {
            if (i & (1 << bit)) {
                b[i] ^= b[i ^ (1 << bit)];
            }
        }
    }
    for (int bit = 0; bit < 19; bit++) {
        for (int i = 0; i < n; i++) {
            if (i & (1 << bit)) {
                b[i ^ (1 << bit)] ^= b[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[n - 1 - i] << " ";
    }
    return 0;
}