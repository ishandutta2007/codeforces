#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1005;
int cnt[5][maxN];
string s[maxN];
int n, m;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) cnt[s[i][j] - 'A'][j]++;
    }
    ll best = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        int mx = 0;
        for (int j = 0; j < 5; j++) mx = max(mx, cnt[j][i]);
        best += mx * a[i];
    }
    cout << best;
    return 0;
}