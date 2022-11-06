#include <bits/stdc++.h>

using namespace std;

const int N = 100005, M = 1e9 + 7;

int n, m;
int a[N], b[N];

void add(int &w, int u) {
    w += u;
    if (w >= M) w -= M;
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int power(int a, int k) {
    if (k == 0) return 1;
    return mul(power(mul(a, a), k / 2), k % 2 ? a : 1);
}

int inv(int w) {
    return power(w, M - 2);
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    
    int ans = 0;
    int curProb = 1;
    
    int ways = mul(((mul(m, m) - m) + M) % M, inv(2));
    
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0 && b[i] > 0) {
            if (a[i] > b[i]) {
                add(ans, curProb);
            }
            if (a[i] != b[i]) {
                break;
            }
        }
        if (a[i] == 0 && b[i] > 0) {
            add(ans, mul(curProb, mul(m - b[i], inv(m))));
            curProb = mul(curProb, inv(m));
        }
        if (a[i] > 0 && b[i] == 0) {
            add(ans, mul(curProb, mul(a[i] - 1, inv(m))));
            curProb = mul(curProb, inv(m));
        }
        if (a[i] == 0 && b[i] == 0) {
            add(ans, mul(curProb, mul(ways, inv(mul(m, m)))));
            curProb = mul(curProb, inv(m));
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}