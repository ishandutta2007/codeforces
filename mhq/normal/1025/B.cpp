#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 15 * (int)1e4 + 100;
int n;
int a[maxN][2];
vector < int > primes(int n) {
    vector < int > cur;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            cur.push_back(i);
        }
    }
    if (n > 1) cur.push_back(n);
    return cur;
}
bool check(int x)  {
    bool can = true;
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        for (int j = 0; j < 2; j++) {
            ok |= ((a[i][j] % x) == 0);
        }
        can &= ok;
    }
    return can;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    vector < int > primes1 = primes(a[1][0]);
    for (int i = 0; i < primes1.size(); i++) {
        if (check(primes1[i])) {
            cout << primes1[i];
            return 0;
        }
    }
    primes1 = primes(a[1][1]);
    for (int i = 0; i < primes1.size(); i++) {
        if (check(primes1[i])) {
            cout << primes1[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}