#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000100;

int n, q;
int ar[maxn];

int main() {
    scanf("%d %d", &n, &q);
    int a = 0, b = 1;
    for (int i = 0; i < q; i++) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int x; scanf("%d", &x);
            a = (a + n + x) % n;
            b = (b + n + x) % n;
        } else {
            a ^= 1, b ^= 1;
        }
    }

    for (int i = 0; i < n / 2; i++) {
        ar[(a + 2 * i) % n] = 2 * i;
        ar[(b + 2 * i) % n] = 2 * i + 1;
    }

    for (int i = 0; i < n; i++) cout << ar[i] + 1 << ' ';
}