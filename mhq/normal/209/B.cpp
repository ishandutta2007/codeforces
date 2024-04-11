#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    long long a, b, c;
    cin >> a >> b >> c;
    long long mn = (1LL << 32);
    if (a % 2 == b % 2) {
        mn = min(mn, max(a, b));
    }
    if (a % 2 == c % 2) {
        mn = min(mn, max(a, c));
    }
    if (b % 2 == c % 2) {
        mn = min(mn, max(b, c));
    }
    cout << mn;
    return 0;
}