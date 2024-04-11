#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, ans, cans;
ll a, b, ac, bc;

void solve() {
    cin >> a >> b;
    ans = 0;
    ac = a;
    bc = b;
    ans = INT_MAX;
    cans = ans;
    while (cans <= ans) {
        if (bc<=1) bc++;
        cans = bc - b;
        ac = a;
        while (ac>0) {
            ac /= bc;
            cans++;
        }
        ans = min(ans, cans);
        bc++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}