#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100010;

int n, a[MAXN], maxa;
ll sum, ans;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        sum += a[i]; maxa = max(maxa, a[i]);
    }
    printf("%I64d\n", max((sum - 1) / (n-1) + 1, ll(maxa)));
}