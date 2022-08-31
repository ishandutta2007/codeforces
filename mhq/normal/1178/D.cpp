#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
bool is_pr(int x) {
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int eds = n;
    while (!is_pr(eds)) eds++;
    assert(eds <= n + n / 2);
    cout << eds << '\n';
    for (int i = 1; i <= n; i++) {
        cout << i << " " << i % n + 1 << '\n';
    }
    for (int i = 1; i <= eds - n; i++) {
        cout << i << " " << i + n / 2 << '\n';
    }
    return 0;
}