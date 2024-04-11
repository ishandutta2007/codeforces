#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct data {
    int w, h, id;
    data() {}
    data(int iw, int ih, int iid) {
        w = iw; h = ih; id = iid;
    }
};

const int MAXN = 5005;

int n, w, h;
data d[MAXN];
int cnt;
int dp[MAXN];
int ret[MAXN], rcnt;

bool cmp(data d1, data d2) {
    return d1.w != d2.w ? d1.w < d2.w : d1.h > d2.h;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d", &n, &w, &h);
    for (int i=0; i<n; i++) {
        int wi, hi;
        scanf("%d %d", &wi, &hi);
        if (wi > w && hi > h) d[cnt++] = data(wi, hi, i);
    }
    if (cnt == 0) {
        printf("0\n");
        return 0;
    }
    sort(d, d+cnt, cmp);
    for (int i=0; i<cnt; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (d[i].w > d[j].w && d[i].h > d[j].h) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int best = 0;
    for (int i=0; i<cnt; i++) best = max(best, dp[i]);
    printf("%d\n", best);
    int cur;
    for (int i=0; i<cnt; i++) {
        if (dp[i] == best) cur = i;
    }
    while (1) {
        ret[rcnt++] = cur;
        if (rcnt == best) break;
        for (int i=0; i<cur; i++) {
            if (dp[i]+1==dp[cur] && d[cur].w > d[i].w && d[cur].h > d[i].h) {
                cur = i;
                break;
            }
        }
    }
    for (int i=rcnt-1; i>=0; i--) printf("%d ", d[ret[i]].id+1);
}