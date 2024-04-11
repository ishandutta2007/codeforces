#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 55;
const int MAXV = 500100;

int n, d, c[MAXN], cur, rt;
bool dp[MAXV];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &d);
    for (int i=0; i<n; i++) scanf("%d", &c[i]);
    dp[0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=MAXV-1; j>=0; j--) {
            if (!dp[j]) continue;
            dp[j + c[i]] = 1;
        }
    }
    for (int t=0; 1; t++) {
        int bef = cur;
        for (int i=min(MAXV-1, cur + d); i>=rt; i--) {
            if (dp[i]) {
                rt = cur + d;
                cur = i;
                break;
            }
        }
        if (cur == bef) {
            printf("%d %d\n", cur, t);
            return 0;
        }
    }
    return 0;
}