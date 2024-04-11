#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, p[3005], inv;

int num(int x) {
    if (x == 0) return 0;
    if (x == 1) return 3;
    if (x == n * (n-1) / 2) return num(x - 2) + 2;
    if (x % 2 == 0) return 4 * (x / 2);
    return 3 + 4 * (x / 2);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &p[i]);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (p[i] > p[j]) { swap(p[i], p[j]); inv++; }
        }
    }
    if (inv == 0) printf("0\n");
    else printf("%d\n", 1 + num(inv-1));
}