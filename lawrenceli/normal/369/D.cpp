#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 3010;

int n, k, p[MAXN], num0[MAXN], num1[MAXN];
bool vis[MAXN][MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &p[i]);
    for (int i=n-1; i>=0; i--) {
        num0[i] = (p[i] == 0) + num0[i+1];
        num1[i] = (p[i] == 100) + num1[i+1];
    }
    queue<pii> q;
    q.push(pii(0, 1));
    for (int t=0; t<=k; t++) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            int a = q.front().fi, b = q.front().se; q.pop();
            if (vis[a][b]) continue;
            vis[a][b] = 1;
            if (b >= n) continue;
            if (p[a] != 100) {
                if (num0[b] != n - b) q.push(pii(b, b+1));
            }
            if (p[a] != 0) {
                if (num1[b] == 0) q.push(pii(a, b+1));
                if (num0[b] != n - b) q.push(pii(b+1, b+2));
            }
        }
    }
    int ans = 0;
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            ans += vis[i][j];
    printf("%d\n", ans);
    return 0;
}