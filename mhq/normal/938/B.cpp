#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mx = max(mx, min(x - 1, (int)1e6 - x));
    }
    cout << mx;
    return 0;
}