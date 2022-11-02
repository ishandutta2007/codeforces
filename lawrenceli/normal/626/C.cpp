#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

bool check(int x) {
    int a = max(n - x / 2 + x / 6, 0);
    int b = max(m - x / 3 + x / 6, 0);
    return a + b <= x / 6;
}

int main() {
    cin >> n >> m;
    int lo = 0, hi = 3000000;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}