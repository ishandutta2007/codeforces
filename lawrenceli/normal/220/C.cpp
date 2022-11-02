#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100010;

int n, a[MAXN], b[MAXN], ia[MAXN], ans[MAXN];
priority_queue<pii> pq1, pq2;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]); a[i]--;
        ia[a[i]] = i;
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &b[i]); b[i]--;
    }
    for (int i=0; i<n; i++) ans[i] = 1e9;
    for (int i=0; i<n; i++) {
        if (i <= ia[b[i]]) {
            pq1.push(pii(-(ia[b[i]] - i), i));
        } else {
            pq2.push(pii(-(i - ia[b[i]]), i));
        }
        ans[0] = min(ans[0], abs(i - ia[b[i]]));
    }
    for (int i=1; i<n; i++) {
        pq2.push(pii(-(n - ia[b[i-1]] - 1 + i), n + i));
        while (!pq2.empty() && -pq2.top().first - i < 0) {
            pq1.push(pii(-(1 - i), pq2.top().second));
            pq2.pop();
        }
        while (!pq1.empty() && pq1.top().second - i < 0) pq1.pop();
        if (!pq1.empty()) ans[i] = min(ans[i], -pq1.top().first + i);
        if (!pq2.empty()) ans[i] = min(ans[i], -pq2.top().first - i);
    }
    for (int i=0; i<n; i++) printf("%d\n", ans[i]);
}