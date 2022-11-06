#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a, b, c;

int main() {

    scanf("%d %d %d", &a, &b, &c);
    if (c == 0) {
        printf(a == b ? "YES\n" : "NO\n");
    } else {
        if (c > 0 && b - a >= 0) {
            printf((b - a) % (c) == 0 ? "YES\n" : "NO\n");
        } else if (c < 0 && a - b >= 0) {
            printf((a - b) % (-c) == 0 ? "YES\n" : "NO\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}