
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
int q, n, a[MAX_N];

int main() {
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << min(n - 2, a[n - 2] - 1) << endl;
    }
}