#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXL = 1000100;

ll n, m, ans;
int xlen, ylen, d, num[2][MAXL][30];
char x[MAXL], y[MAXL];

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%I64d %I64d", &n, &m);
    scanf("\n%s\n%s", x, y);
    xlen = strlen(x), ylen = strlen(y);
    d = gcd(xlen, ylen);
    for (int i=0; i<xlen; i++) num[0][i%d][x[i]-'a'] ++;
    for (int i=0; i<ylen; i++) num[1][i%d][y[i]-'a'] ++;
    for (int i=0; i<d; i++) {
        for (int j=0; j<30; j++) {
            ans += ll(num[0][i][j]) * num[1][i][j];
        }
    }
    ans = ll(xlen) * ylen / d - ans;
    printf("%I64d\n", ans * (n * d / ylen));
    return 0;
}