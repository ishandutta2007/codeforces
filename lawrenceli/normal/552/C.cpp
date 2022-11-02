#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int w, m;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> w >> m;
    ll sum = 0, cur = 1;
    for (int i=0; i<=100; i++) {
        ll x = m-cur+sum;
        if (x < 0) break;
        bool good = 1;
        for (int j=0; j<i; j++) {
            if (x%w > 2) { good = 0; break; }
            x /= w;
        }
        if (x > 0) good = 0;
        if (good) {
            cout << "YES\n";
            return 0;
        }
        sum += cur;
        cur *= w;
    }
    cout << "NO\n";
}