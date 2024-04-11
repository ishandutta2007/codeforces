#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int MAXA = 1000010;
const int MOD = 1e9+7;

int n;
int a[MAXN], dp[MAXN];
int bit[MAXA], val[MAXA];

int query(int i) {
    int sum=0;
    for (; i>0; i-=i&-i) sum=(sum+bit[i])%MOD;
    return sum;
}

void update(int i, int p) {
    val[i]=(val[i]+p)%MOD;
    for (; i<MAXA; i+=i&-i) bit[i]=(bit[i]+p)%MOD;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) {
        dp[i]=((long long)(query(a[i])+1)*a[i])%MOD;
        update(a[i], (dp[i]-val[a[i]]+MOD)%MOD);
    }
    int tot=0;
    for (int i=0; i<MAXA; i++) tot=(tot+val[i])%MOD;
    printf("%d\n", tot);
}