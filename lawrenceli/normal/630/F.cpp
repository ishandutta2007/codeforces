#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

bool b[10];

ll C(int n, int k) {
    ll res = 1;
    memset(b, 0, sizeof(b));
    for (int i = n; i > n - k; i--) {
        res *= i;
        for (int i = 1; i <= k; i++)
            if (!b[i] && res % i == 0)
                b[i] = 1, res /= i;
    }
    return res;
}

int main() {
    int n; cin >> n;
    cout << C(n, 5) + C(n, 6) + C(n, 7) << '\n';
}