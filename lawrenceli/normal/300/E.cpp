#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXK = 1e6 + 5;
const int MAXA = 1e7 + 5;

int k;
int a[MAXK], p[MAXA], pnt;
bool prime[MAXA];
int primes[MAXK], size;
ll num[MAXK];

bool pos(ll mid) {
    for (int i=0; i<size; i++) {
        ll tot = 0;
        for (ll j = primes[i]; mid / j > 0; j*=primes[i]) tot += mid / j;
        if (tot < num[i]) return 0;
    }
    return 1;
}


int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &k);
    for (int i=0; i<k; i++) scanf("%d", &a[i]);
    sort(a, a+k);
    for (int i=0; i<MAXA; i++) prime[i] = 1;
    for (int i=2; i<MAXA; i++) {
        if (prime[i]) {
            primes[size++] = i;
            for (int j=2*i; j<MAXA; j+=i) prime[j] = 0;
        }
    }
    for (int i=1; i<MAXA; i++) {
        p[i] = k - pnt;
        while (pnt < k && a[pnt] == i) pnt++;
    }
    for (int i=0; i<size; i++) {
        for (ll j=primes[i]; j<MAXA; j*=primes[i]) {
            for (int k=j; k<MAXA; k+=j) num[i] += p[k];
        }
    }
    ll lo = 1, hi = 1e15;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (pos(mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%I64d\n", lo);
}