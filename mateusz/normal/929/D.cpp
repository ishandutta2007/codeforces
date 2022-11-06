#include <bits/stdc++.h>

using namespace std;

const int BASE = 131072, N = 100005;
const long long INF = 1e18;

int firstLeft[2 * BASE + 5], firstRight[2 * BASE + 5];

int n, a, b;
int gate[N], key[N], last[N];

bool vis[N][2];

long long solveRight(int w);
long long solveLeft(int w);

int query(int *tree, int posa, int posb) {
    posa += BASE;
    posb += BASE;
    int ret = min(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = min(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = min(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int getLeft(int posa, int posb) {
    return query(firstLeft, posa, posb);
}

int getRight(int posa, int posb) {
    return -query(firstRight, posa, posb);
}

long long solveRight(int w) {
    if (w == a) {
        return 0;
    }
    if (vis[w][0]) return INF;
    vis[w][0] = true;
    int minLeft = getLeft(a, w - 1);
    if (minLeft == 0) {
        return INF;
    }
    return abs(w - minLeft) + solveLeft(minLeft);
}

long long solveLeft(int w){
    if (w == a) {
        return 0;
    }
    if (vis[w][1]) return INF;
    vis[w][1] = true;
    int maxRight = getRight(w, a - 1);
    if (maxRight > b) {
        return INF;
    }
    return abs(w - maxRight) + solveRight(maxRight);
}

int main() {
    
    scanf("%d %d %d", &n, &a, &b);
    
    int mx = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", &gate[i]);
        mx = max(mx, gate[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &key[i]);
        mx = max(mx, key[i]);
    }
    
    if (a > b) {
        reverse(gate + 1, gate + n);
        reverse(key + 1, key + 1 + n);
        b = n - b + 1;
        a = n - a + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        last[key[i]] = i;
        if (i < n) {
            firstLeft[i + BASE] = last[gate[i]];
        }
    }
    
    for (int i = 0; i <= mx; i++) {
        last[i] = n + 1;
    }
    for (int i = n; i >= 1; i--) {
        if (i < n) {
            firstRight[i + BASE] = -last[gate[i]];
        }
        last[key[i]] = i;
    }
    
    for (int i = BASE - 1; i >= 1; i--) {
        firstRight[i] = min(firstRight[2 * i], firstRight[2 * i + 1]);
        firstLeft[i] = min(firstLeft[2 * i], firstLeft[2 * i + 1]);
    }
    
    long long ans = solveRight(b);
    if (ans >= INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", ans);
    }
    
    return 0;
}