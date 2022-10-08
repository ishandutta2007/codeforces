#include <cstdio>

int main() {
    int d = 0;
    scanf("%d", &d);
    for (int i = 0; i < d; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (y < x) {
            printf("%d\n", x + y);
        } else {
            printf("%d\n", y - (y % x) / 2);
        }
    }
}