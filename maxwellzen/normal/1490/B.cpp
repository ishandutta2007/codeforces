#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, x, r[3];

void solve() {
    r[0]=0; r[1]=0; r[2]=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        r[x%3]++;
    }
    int ans = 0;
    int g = n/3;
    while (r[0] != g || r[1] != g || r[2] != g) {
        for (int i = 0; i < 3; i++) {
            if (r[i]>g) {
                r[(i+1)%3] += r[i] - g;
                ans += r[i] - g;
                r[i] = g;
            }
        }
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