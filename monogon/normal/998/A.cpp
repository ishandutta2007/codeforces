
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int m = 10000, j = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        if(a < m) {
            m = a;
            j = i;
        }
    }
    if(2 * m == sum || n < 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << 1 << endl << j + 1 << endl;
}