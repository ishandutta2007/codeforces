#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll exp(int b, int e) {
    ll res = 1;
    for (int i = 0; i < e; i++) res *= b;
    return res;
}

int main() {
    int n; cin >> n;
    cout << 4 * (6 * exp(4, n - 3) + (n - 3) * 9 * exp(4, n - 4)) << '\n';
}