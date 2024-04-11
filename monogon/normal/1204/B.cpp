
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, l, r;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> l >> r;
    cout << ((n - l) + ((1 << l) - 1))
        << " " << ((1 << r) - 1) + (n - r) * (1 << (r - 1)) << endl;
}