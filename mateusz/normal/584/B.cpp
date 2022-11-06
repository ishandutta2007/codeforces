#include <bits/stdc++.h>

using namespace std;

const int N = 100005, M = 1e9 + 7;

int n;

long long power(long long a, long long k) {
    if (k == 0) {
        return 1;
    }
    return power(a * a % M, k / 2) * (k % 2 == 1 ? a : 1) % M;
}

int main() {

    scanf("%d", &n);

    printf("%d\n", (int)(((power(3, 3 * n) - power(7, n)) % M + M) % M));

    return 0;
}