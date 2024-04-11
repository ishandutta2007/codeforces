#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 5000100;
const ll MULT1 = 1e9 + 7;
const ll MULT2 = 1e9 + 9; //double check

char s[MAXN];
int n, deg[MAXN], ans;
ll pre1[MAXN], pre2[MAXN], suf1[MAXN], suf2[MAXN], exp1[MAXN], exp2[MAXN];

bool check(int l, int r) {
    ll a1 = pre1[r+1] - pre1[l], a2 = pre2[r+1] - pre2[l];
    ll b1 = suf1[l] - suf1[r+1], b2 = suf2[l] - suf2[r+1];
    ll e = n-l-r-1;
    if (e >= 0) return a1 * exp1[e] == b1 && a2 * exp2[e] == b2;
    return a1 == b1 * exp1[-e] && a2 == b2 * exp2[-e];
}

int calc(int k) {
    if (k == -1) return 0;
    if (deg[k] != -1) return deg[k];
    return deg[k] = (check(0, k) ? calc((k+1) / 2 - 1) + 1 : 0);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%s", s); n = strlen(s);
    exp1[0] = exp2[0] = 1;
    for (int i=1; i<=n; i++) {
        exp1[i] = exp1[i-1] * MULT1;
        exp2[i] = exp2[i-1] * MULT2;
    }
    for (int i=0; i<n; i++) {
        pre1[i+1] = pre1[i] + exp1[i] * s[i];
        pre2[i+1] = pre2[i] + exp2[i] * s[i];
    }
    for (int i=n-1; i>=0; i--) {
        suf1[i] = suf1[i+1] + exp1[n-i-1] * s[i];
        suf2[i] = suf2[i+1] + exp2[n-i-1] * s[i];
    }
    for (int i=0; i<n; i++) deg[i] = -1;
    for (int i=0; i<n; i++) ans += calc(i);
    printf("%d\n", ans);
    return 0;
}