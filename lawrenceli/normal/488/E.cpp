#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n;

int pow(int b, int e) {
    if (!e) return 1;
    if (e&1) return ll(b)*pow(b, e-1)%n;
    int res = pow(b, e/2);
    return ll(res)*res%n;
}

int main() {
    cin >> n;
    if (n == 1) {
        cout << "YES\n1\n";
        return 0;
    }

    if (n == 4) {
        cout << "YES\n1\n3\n2\n4\n";
        return 0;
    }

    for (int i=2; i<n; i++)
        if (n%i == 0) {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n1\n";
    for (int i=2; i<n; i++)
        cout << ll(i)*pow(i-1, n-2)%n << '\n';
    cout << n << '\n';
    return 0;
}