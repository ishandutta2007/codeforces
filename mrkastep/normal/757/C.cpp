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

map<vector<pair<int, int> >, int> d;

map<int, int> s[100100];

vector<pair<int, int> > v[1001000];

ll fct[1001000];

void solve() {
    fct[0] = 1;
    for (int i = 1; i < 1001000; ++i)
        fct[i] = fct[i - 1] * i % mod;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int a;
            scanf("%d", &a);
            --a;
            ++s[i][a];
        }
        for (auto it : s[i])
            v[it.first].eb(i, it.second);
    }
    for (int i = 0; i < m; ++i)
        ++d[v[i]];
    ll ans = 1;
    for (auto it : d)
        ans *= fct[it.second], ans %= mod;
    cout << ans;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}