#include <cstdio>

typedef long long ll;

const int MAXN = 200010;

int n, k, x[MAXN], ind[MAXN], cur, cur2;
ll val, y[MAXN], arr[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &x[i]);
    for (int i=0; i<k; i++) val += x[i];
    for (int i=0; i<n-k+1; i++) {
        y[i] = val;
        val += x[i+k] - x[i];
    }
    val = 0;
    for (int i=n-k+1; i>=0; i--) {
        if (y[i] >= val) {
            val = y[i], cur = i;
        }
        arr[i] = cur;
    }
    val = 0;
    for (int i=0; i<n-2*k+1; i++) {
        if (y[i] + y[arr[i+k]] > val) {
            val = y[i] + y[arr[i+k]], cur = i, cur2 = arr[i+k];
        }
    }
    printf("%d %d\n", cur+1, cur2+1);
}