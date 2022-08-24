#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 7005;
ll a[maxN], b[maxN];
map < ll, int > mp;
bool good[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (mp[a[i]] >= 2) good[i] = true;
    }
    ll best = 0;
    for (int i = 1; i <= n; i++) {
        if (good[i]) {
            best += b[i];
            continue;
        }
        bool ok = false;
        for (int j = 1; j <= n; j++) {
            if (!good[j]) continue;
            if ((a[i] & a[j]) == a[i]) {
                ok = true;
                break;
            }
        }
        if (ok) best += b[i];
    }
    cout << best;
    return 0;
}