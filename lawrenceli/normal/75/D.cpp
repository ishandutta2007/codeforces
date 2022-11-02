#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 55;
const int MAXM = 250100;
const int MAXL = 5005;
const ll INF = 1e18;

int n, m, l[MAXN], mat[MAXN][MAXL], ar[MAXM];
ll lt[MAXN], rt[MAXN], ma[MAXN], sum[MAXN], ans, cur;

void setmax(ll& a, ll b) { if (a < b) a = b; }

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &l[i]);
        for (int j=0; j<l[i]; j++)
            scanf("%d", &mat[i][j]);
        ll x = 0;
        lt[i] = rt[i] = ma[i] = -INF;
        for (int j=0; j<l[i]; j++)
            x += mat[i][j], setmax(lt[i], x);
        sum[i] = x, x = 0;
        for (int j=l[i]-1; j>=0; j--)
            x += mat[i][j], setmax(rt[i], x);
        x = 0;
        for (int j=0; j<l[i]; j++)
            x = max(x, 0LL)+mat[i][j], setmax(ma[i], x);
    }
    ans = -INF;
    for (int i=0; i<m; i++) {
        scanf("%d", &ar[i]);
        ar[i]--;
        setmax(ans, cur+lt[ar[i]]);
        setmax(ans, ma[ar[i]]);
        cur = max(cur+sum[ar[i]], rt[ar[i]]);
    }
    setmax(ans, cur);
    printf("%I64d\n", ans);
    return 0;
}