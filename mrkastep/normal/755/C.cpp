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

int p[10100];

int fs(int v) {
    return p[v] == v ? v : (p[v] = fs(p[v]));
}

void us(int a, int b) {
    a = fs(a);
    b = fs(b);
    if (a == b)
        return;
    p[a] = b;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        us(i, a);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (fs(i) == i)
            ++ans;
    }
    printf("%d\n", ans);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}