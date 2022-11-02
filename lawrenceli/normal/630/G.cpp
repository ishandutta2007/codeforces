#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll C(int n, int k) {
    ll res = 1;
    for (int i = n; i > n - k; i--) res *= i;
    for (int i = 1; i <= k; i++) res /= i;
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << C(n + 4, 5) * C(n + 2, 3) << '\n';
}