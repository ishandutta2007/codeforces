#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if (is_prime(n)) {
        cout << 1 << "\n" << n << '\n';
    }
    else {
        if (n % 2 == 0) {
            for (int a = 2; a <= n; a++) {
                if (is_prime(a) && is_prime(n - a)) {
                    cout << 2 << '\n' << a << " " << n - a;
                    return 0;
                }
            }
        }
        else {
            n -= 3;
            for (int a = 2; a <= n; a++) {
                if (is_prime(a) && is_prime(n - a)) {
                    cout << 3 << "\n" << 3 << " " << a << " " << n - a << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}