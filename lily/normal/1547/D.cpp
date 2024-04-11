#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int x[N], y[N];

void work() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", x + i);
    }
    int must = 0;
    for (int i = 0; i < n; i++) {
        y[i] = 0;
        for (int j = 0; j < 31; j++) {
            if ((must >> j) & 1) y[i] |= ((~x[i] >> j) & 1) << j;
        }
        printf("%d ", y[i]);
        must = x[i] ^ y[i];
    }
    puts("");
    
    
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
}