
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m;
ll a[N], pref[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        pref[i] = a[i] + pref[i - 1];
        dp[i] = (i > m ? dp[i - m] : 0) + pref[i];
        cout << dp[i] << " ";
    }
    cout << endl;
}