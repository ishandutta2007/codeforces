
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, a, sum, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
        }
        cout << (sum + n - 1) / n << endl;
    }
}