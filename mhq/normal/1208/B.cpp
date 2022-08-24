#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2005;
int a[maxN];
int cnt[maxN];
int cnt_bad;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f.push_back(a[i]);
    }
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(f.begin(), f.end(), a[i]) - f.begin();
    }
    int mn = n + 100;
    for (int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof cnt);
        for (int j = 1; j <= n; j++) {
            cnt[a[j]]++;
        }
        for (int j = 0; j <= n; j++) {
            if (cnt[j] > 1) cnt_bad++;
        }
        if (cnt_bad == 0) {
            cout << 0;
            return 0;
        }
        for (int j = i; j <= n; j++) {
            cnt[a[j]]--;
            if (cnt[a[j]] == 1) cnt_bad--;
            if (cnt_bad == 0) {
                mn = min(mn, j - i + 1);
                break;
            }
        }
    }
    cout << mn;

    return 0;
}