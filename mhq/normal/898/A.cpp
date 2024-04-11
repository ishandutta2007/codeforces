#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n % 10 <= 5) cout << (n - (n % 10));
    else cout << (n - (n % 10) + 10);
    return 0;
}