#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    cin >> T;
    while (T -- ) {
        int n, k;
        cin >> n >> k;
        int mi = max(k, n);
        if ((mi - k) % 2) ++ mi;
        cout << mi - n << '\n';
    }
}