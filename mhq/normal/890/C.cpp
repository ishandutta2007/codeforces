#include <bits/stdc++.h>
using namespace std;
int n;
int t[2 * (int)1e5 + 5];
bool used[2 * (int)1e5 + 5];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        used[t[i]] = true;
    }
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (!used[i]) cnt++;
    }
    cout << cnt;
}