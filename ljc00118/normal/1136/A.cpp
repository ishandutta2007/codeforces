#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int l[N], r[N];
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    cin >> k;
    for (int i = 1; i <= n; i++) {
        if(l[i] <= k && k <= r[i]) {
            cout << n - i + 1 << endl;
            return 0;
        }
    }
    return 0;
}