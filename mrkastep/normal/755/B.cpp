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
    int n, m, a = 0;
    map<string, int> v;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v[s]++;
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        a += v[s];
    }
    if (a % 2 == 0) {
        if (n > m)
            puts("YES");
        else
            puts("NO");
    }
    else
        if (n >= m)
            puts("YES");
        else
            puts("NO");



}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}