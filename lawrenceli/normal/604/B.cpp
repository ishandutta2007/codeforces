#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100100;

int n, k, s[maxn];

bool check(int x) {
    int p = 0;
    for (; p < n && s[p] + s[0] <= x; p++);
    p--;

    for (int i = 0; i < n - k; i++) {
        while (p > i && s[p] + s[i] > x) p--;
        if (p <= i) return 0;
        p--;
    }

    return 1;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> s[i];

    int lo = s[n - 1], hi = 2000000;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}