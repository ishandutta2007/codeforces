#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

int x1, y1, x2, y2;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2 || y1 == y2) printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
        else printf("%d\n", abs(x1 - x2) + abs(y1 - y2) + 2);
    }   
    return 0;
}