#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    if (n > 50) cout << m;
    else cout << m % (1LL << n);
    return 0;
}