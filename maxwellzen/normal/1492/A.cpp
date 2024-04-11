#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t;
ll p, a, b, c;

void solve() {
    cin >> p >> a >> b >> c;
    cout << min({((p-1)/a + 1)*a, ((p-1)/b+1)*b, ((p-1)/c+1)*c})-p << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}