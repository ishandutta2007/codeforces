#include <bits/stdc++.h>

using namespace std;

int n, k;
const int ge[] = {0,1,2,0,1,0,1};
const int go[] = {0,1,0,1,2,0,2};

int G(int x) {
    if (k & 1) {
        if (x <= 6) return go[x];
        if (x & 1) return 0;
        if (x & 2) return 1;
        return 3 - G(x / 2);
    }
    else {
        if (x <= 6) return ge[x];
        return 1 - (x & 1);
    }
}

int main(void) {
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans ^= G(x);
    }
    cout << (ans ? "Kevin" : "Nicky") << endl;
}