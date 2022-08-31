#include <set>
#include <map>
#include <cmath>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <chrono>

#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;

const ll max_n = 100011;

int n, u, a[max_n];
pair<int, int> ans = make_pair(1, 1000111222);

void update(int a, int b) {
    if (b > u) return;
    if (1LL * ans.F * b < 1LL * ans.S * a) {
        ans = make_pair(a, b);
    }
}

int main() {
    cin >> n >> u;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int st = 0, fn = 2;
    for (int i = 0; i < n; ++i) {
        st = i;
        while (fn + 1 < n && a[fn + 1] <= a[st] + u) {
            ++fn;
        }
        if (st + 2 <= fn)
            update(a[fn] - a[st + 1], a[fn] - a[st]);
    }
    if (ans.S == 1000111222)
        cout << -1 << endl;
    else printf("%.14f", (1. * ans.F) / ans.S);
    return 0;
}