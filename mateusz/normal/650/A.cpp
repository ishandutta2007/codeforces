#include <bits/stdc++.h>

using namespace std;

const int N = 100005, INF = 1e9 + 5;

unordered_map<int, int> cols, rows;
unordered_map<long long, int> both;
int x, y, n;

int main() {

    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        int c = 0, r = 0, b = 0;
        if (cols.count(x)) {
            c = cols[x];
            cols[x]++;
        } else {
            cols[x] = 1;
        }
        if (rows.count(y)) {
            r = rows[y];
            rows[y]++;
        } else {
            rows[y] = 1;
        }
        if (both.count((long long)x * INF + y)) {
            b = both[(long long)x * INF + y];
            both[(long long)x * INF + y]++;
        } else {
            both[(long long)x * INF + y] = 1;
        }
        ans += c + r - b;
    }
    printf("%lld\n", ans);

    return 0;
}