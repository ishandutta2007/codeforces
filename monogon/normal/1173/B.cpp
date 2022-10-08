
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
// 2m - 1 >= n
// 2m >= n + 1
// m = (n + 2) / 2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int m = (n + 2) / 2;
    cout << m << '\n';
    for(int i = 1; i <= min(m, n); i++) {
        cout << "1 " << i << '\n';
    }
    for(int i = 2; i - 1 + m <= n; i++) {
        cout << i << " " << m << '\n';
    }
}