
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    for(int i = 0; i < n; i++) cin >> r[i] >> r[i];
    int k;
    cin >> k;
    int ans = 0;
    for(int i = 0; i < n; i++) ans += (k <= r[i]);
    cout << ans << '\n';
}