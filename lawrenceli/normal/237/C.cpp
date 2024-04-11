#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXA = 1000100;

int a, b, k;
bool prime[MAXA];

void init() {
    for (int i=2; i<MAXA; i++) prime[i] = 1;
    for (int i=2; i<MAXA; i++) {
        if (!prime[i]) continue;
        for (int j=2*i; j<MAXA; j+=i) prime[j] = 0;
    }
}

bool pos(int mid) {
    int cur = 0;
    for (int i=a; i<a+mid; i++) cur += prime[i];
    for (int i=a; i<=b-mid+1; i++) {
        if (cur < k) return 0;
        cur -= prime[i]; cur += prime[i+mid];
    }
    return 1;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    init();
    scanf("%d %d %d", &a, &b, &k);
    int lo = 1, hi = b - a + 2;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (pos(mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%d\n", lo == b - a + 2 ? -1 : lo);
    return 0;
}