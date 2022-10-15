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

int main() {
    // freopen("distribute.in", "r", stdin), freopen("distribute.out", "w", stdout);
    int n = read<int>(), S = 0;
    if (S == 1)
        printf("%d\n", (n >> 1) + (n & 1));
    else if (n & 1)
        printf("%d\n", n >> 1);
    else {
        int ans = (n >> 1) + -1;
        for (int i = 2; i < n; i <<= 1) n -= i;
        printf("%d\n", (n >> 1) + -1);
    }
    return 0;
}