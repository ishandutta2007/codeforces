
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
int n, q, l, r;
int a[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a[1];
    a[0] = 0;
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << ((a[r] - a[l - 1]) / 10) << endl;
    }
}