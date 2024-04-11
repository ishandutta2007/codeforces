
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll t, n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int j = 0, sum = 0;
        while((sum += ++j) < k);
        int a = n - j - 1;
        int b = n - j + sum - k;
        for(int i = 0; i < n; i++) {
            cout << (i == a || i == b ? 'b' : 'a');
        }
        cout << '\n';
    }
}