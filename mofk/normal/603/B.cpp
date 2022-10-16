#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int pw(int a, int b, int m) {
    int r = 1;
    for (int i = 0; i < b; ++i) r = 1LL * r * a % m;
    return r;
}

int main(void) {
    int p, k;
    cin >> p >> k;
    if (k == 0) return cout << pw(p, p - 1, mod) << endl, 0;
    if (k == 1) return cout << pw(p, p, mod) << endl, 0;
    int cur = k, cnt = 1;
    while (cur != 1) cur = 1LL * cur * k % p, ++cnt;
    assert((p - 1) % cnt == 0);
    cout << pw(p, (p - 1) / cnt, mod) << endl;
}