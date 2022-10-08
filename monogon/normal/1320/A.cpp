
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll b[N];
map<int, ll> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        m[i - b[i]] += b[i];
    }
    ll ans = 0;
    for(auto p : m) ans = max(ans, p.second);
    cout << ans << endl;
}