#include <cstdio>

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    int x, y, a, b, cnt = 0, gcd = 1, lcm;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    for (int i=x*y - 1; i>0; i--) {
        if (x%i == 0 && y%i == 0) {
            gcd = i; break;
        }
    }
    lcm = x * y / gcd;
    while (a % lcm != 1 && lcm != 1 && a < b) {
        if (!(a % lcm)) cnt++;
        a++;
    }
    printf("%d\n", (b - a + 1) / lcm + cnt);
}