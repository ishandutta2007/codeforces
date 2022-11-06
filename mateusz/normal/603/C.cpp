#include <bits/stdc++.h>

using namespace std;

int n, k, x;
int stan[205];

int main() {

    int ans = 0;

    scanf("%d %d", &n, &k);

    if (k % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x <= 2) {
                ans ^= x;
            } else {
                ans ^= (x - 1) % 2;
            }
        }
    } else {

        for (int i = 1; i <= 200; i++) {
            if (i % 2 == 1) {
                stan[i] = stan[i - 1] ? 0 : 1;
            } else {
                int a = k % 2 ? stan[i / 2] : 0;
                int b = stan[i - 1];
                if (a && b) {
                    stan[i] = 0;
                } else {
                    if (a > b) {
                        swap(a, b);
                    }
                    if (b == 1) {
                        stan[i] = 2;
                    } else {
                        stan[i] = 1;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x <= 200) {
                ans ^= stan[x];
            } else {
                if (x % 2 == 1) {
                    continue;
                }
                if (__builtin_ctz(x) % 2 == 1) {
                    ans ^= 1;
                } else {
                    ans ^= 2;
                }
            }
        }
    }

    printf(ans ? "Kevin\n" : "Nicky\n");

    return 0;
}