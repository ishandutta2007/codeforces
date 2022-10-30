#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <valarray>
#include <tuple>
#include <complex>
#include <bitset>
#include <assert.h>
#include <unordered_map>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;

const int INF = 2e9;
const int mod = 1e9 + 7;

using namespace std;

void solve() {
    vector<pair<int, ll> > ans;
    ans.eb(-1e9, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        ll s = ans.back().second + 20;
        cin >> t;
        auto it = prev(upper_bound(ans.begin(), ans.end(), pair<int, ll>(t - 90, 2e9)));
        s = min(s, it->second + 50);
        it = prev(upper_bound(ans.begin(), ans.end(), pair<int, ll>(t - 1440, 2e9)));
        s = min(s, it->second + 120);
        printf("%I64d\n", s - ans.back().second);
        ans.eb(t, s);
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}