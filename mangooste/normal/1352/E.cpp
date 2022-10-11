#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(n + 1, 0);
        for (auto &el : a) {
            cin >> el;
            cnt[el]++;
        }
        vector<char> can(n + 1, 0);
        vector<int> pr;
        pr.pb(0);
        for (int i = 0; i < n; i++)
            pr.pb(pr.back() + a[i]);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i - 1; j++)
                if (pr[i] - pr[j] <= n && !can[pr[i] - pr[j]])
                    can[pr[i] - pr[j]] = 1;
        for (int i = 1; i <= n; i++)
            if (can[i])
                ans += cnt[i];
        cout << ans << '\n';
    }
}