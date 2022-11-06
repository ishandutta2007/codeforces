#include <bits/stdc++.h>

using namespace std;

long long n;
char pos;

int main() {

    scanf("%lld%c", &n, &pos);
    n--;
    long long ans = 0;
    ans = n / 4 * 16;

    n %= 4;
    if (n % 2 == 1) {
        ans += 7;
    }

    if (pos == 'f') {
        ans++;
    } else if (pos == 'e') {
        ans += 2;
    } else if (pos == 'd') {
        ans += 3;
    } else if (pos == 'a') {
        ans += 4;
    } else if (pos == 'b') {
        ans += 5;
    } else if (pos == 'c') {
        ans += 6;
    }

    printf("%lld\n", ans);

    return 0;
}