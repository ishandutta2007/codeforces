#include<bits/stdc++.h>
using namespace std;

bool solve () {
    int n, k;

    scanf("%d %d", &n, &k);

    long long sum = 1LL * k * k;
    long long res = n - sum;

    if (res < 0) return false;

    if (res % 2) return false;

    return true;
}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ; ) {

        puts(solve() ? "YES" : "NO");
    }
}