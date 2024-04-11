#include <cstdio>
#include <iostream>
using namespace std;
int c, s;
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &c, &s);
        int f = s % c;
        int cost = s / c;
        if(f) {
            printf("%d\n", (c - f) * cost * cost + f * (cost + 1) * (cost + 1));
        } else printf("%d\n", c * cost * cost);
    }
    return 0;
}