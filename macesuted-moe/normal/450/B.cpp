/*
 *  Macesuted Kysic
 *  Oct. 29th 2020
 */

#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

const int mod = 1000000007;

int main() {
    int x = read<int>(), y = read<int>();
    int n = read<int>() % 6, ans = 0;
    switch (n) {
        case 1:
            ans = x;
            break;
        case 2:
            ans = y;
            break;
        case 3:
            ans = y - x;
            break;
        case 4:
            ans = -x;
            break;
        case 5:
            ans = -y;
            break;
        case 0:
            ans = x - y;
            break;
    }
    printf("%d\n", (ans % mod + mod) % mod);
    return 0;
}