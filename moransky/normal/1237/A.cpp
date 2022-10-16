#include <cstdio>
#include <iostream>
using namespace std;
const int N = 13850;
int n, a[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int f = 0;
    for (int i = 1; i <= n; i++) {
        if(a[i] & 1) {
            if(f) printf("%d\n", (a[i] >> 1) + 1);
            else printf("%d\n", a[i] >> 1);
            f ^= 1;
        } else printf("%d\n", a[i] >> 1);
    }
}