#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 20100;

int n, m, p;
int x[MAXN], y[MAXN];
int dp1[MAXN], dp2[MAXN];
char ans[2*MAXN];
int cnt;

int go(int s1, int s2, int e1, int e2) {
    if (s1 == e1) {
        int ret = (x[s1]+y[s2])%p;
        for (int i=s2+1; i<=e2; i++)
            ret += (x[s1]+y[i])%p, ans[cnt++] = 'S';
        return ret;
    } else {
        int mid = (s1+e1)/2;
        for (int i=s2-1; i<=e2+1; i++) dp1[i]=dp2[i]=0;
        for (int i=s1; i<=mid; i++)
            for (int j=s2; j<=e2; j++)
                dp1[j] = max(dp1[j], dp1[j-1])+(x[i]+y[j])%p;
        for (int i=e1; i>=mid; i--)
            for (int j=e2; j>=s2; j--)
                dp2[j] = max(dp2[j], dp2[j+1])+(x[i]+y[j])%p;
        int v = -1e9, a = -1;
        for (int i=s2; i<=e2; i++) {
            int w = dp1[i]+dp2[i]-(x[mid]+y[i])%p;
            if (w>=v) v=w, a=i;
        }
        int ret = go(s1, s2, mid, a);
        ans[cnt++] = 'C';
        ret += go(mid+1, a, e1, e2);
        return ret;
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &p);
    for (int i=1; i<=n; i++) scanf("%d", &x[i]);
    for (int i=1; i<=m; i++) scanf("%d", &y[i]);
    int res = go(1, 1, n, m);
    printf("%d\n%s\n", res, ans);
    return 0;
}