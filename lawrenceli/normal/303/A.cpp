#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, a[maxn], b[maxn], c[maxn];

int main() {
    cin >> n;
    if (n%2 == 0) cout << -1;
    else {
        for (int i=0; i<n; i++) {
            a[i] = i;
            b[i] = i;
            c[i] = (a[i]+b[i])%n;
        }

        for (int i=0; i<n; i++) cout << a[i] << ' ';
        cout << endl;
        for (int i=0; i<n; i++) cout << b[i] << ' ';
        cout << endl;
        for (int i=0; i<n; i++) cout << c[i] << ' ';
        cout << endl;
    }
}