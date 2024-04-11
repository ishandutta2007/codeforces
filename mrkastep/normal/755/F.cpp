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

int p[1001000];

int d[1001000];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1)
            continue;
        int s = 0;
        while (p[i] != -1) {
            int t = p[i];
            p[i] = -1;
            i = t;
            ++s;
        }
        v.pb(s);
    }
    sort(v.begin(), v.end());
    int mx = 0, mn;
    int t = k;
    for (int i = v.size() - 1; i >= 0; --i) {
        int val = min(t, v[i] / 2);
        t -= val;
        mx += 2 * val;
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        int val = min(t, v[i] % 2);
        t -= val;
        mx += val;
    }
    memset(d + 1, 0, k * sizeof(int));
    d[0] = 1;
    int mxps = 0;
    for (int i = 0; i < v.size();) {
        int l;
        for (l = i; l < v.size() && v[l] == v[i]; ++l);
        l -= i;
        int a = v[i];
        for (int j = mxps; j >= 0; --j) {
            if (d[j]) {
                for (int m = 1; m <= l && j + m * a <= k && d[j + m * a] == 0; ++m)
                    d[j + m * a] = 1, mxps = max(mxps, j + m * a);
            }
        }
        i += l;
    }
    mn = min(n, k + 1);
    if (d[k])
        mn = k;
    printf("%d %d", mn, mx);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}