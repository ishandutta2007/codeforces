#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxK = 1e6 + 10;
const int maxN = 1005;
ll a[maxN];
int used[maxK];
vector<int> g[maxK];
int mt[maxN];
int ITER = 0;
bool kuhn(int v) {
    if (used[v] == ITER) return false;
    used[v] = ITER;
    for (int to : g[v]) {
        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> nums;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            nums.emplace_back(a[i] * j);
        }
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int f = lower_bound(nums.begin(), nums.end(), a[i] * j) - nums.begin();
            g[f].emplace_back(i);
        }
    }
    ll ans = 0;
    memset(mt, -1, sizeof mt);
    ITER++;
    for (int i = 0; i < nums.size(); i++) {
        bool has = false;
        for (int t : g[i]) {
            if (mt[t] == -1) {
                has = true;
                mt[t] = i;
                ans += nums[i];
                ITER++;
                break;
            }
        }
        if (!has) {
            if (kuhn(i)) {
                ITER++;
                ans += nums[i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}