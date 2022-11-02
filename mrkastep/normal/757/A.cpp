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

const int INF = 2e9;

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cnt[200];
    for (int i = 0; i < 200; ++i)
        cnt[i] = 0;
    for (auto i : s)
        cnt[i]++;
    int ans = INF;
    ans = min(ans, cnt['B'] / 1);
    ans = min(ans, cnt['u'] / 2);
    ans = min(ans, cnt['l'] / 1);
    ans = min(ans, cnt['b'] / 1);
    ans = min(ans, cnt['a'] / 2);
    ans = min(ans, cnt['s'] / 1);
    ans = min(ans, cnt['r'] / 1);
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