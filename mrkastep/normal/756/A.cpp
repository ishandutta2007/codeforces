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

int p[200200], b[200200];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
    }
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    int cnt = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) {
            ++cnt;
            int cur = p[i];
            int t;
            p[i] = -1;
            while (cur != i) {
                t = cur;
                cur = p[cur];
                p[t] = -1;
            }
        }
        s += b[i];
    }
    cout << (cnt > 1 ? cnt : 0) + ((s + 1) % 2) << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}