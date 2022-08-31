#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n % 2 == 1) {
        cout << 0;
        return 0;
    }
    cout << (1LL << (n / 2));
    return 0;
}