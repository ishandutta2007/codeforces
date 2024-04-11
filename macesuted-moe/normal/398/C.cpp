/**
     * @author Macesuted
     * @date 2021-02-03
     * 
     * @copyright Copyright (c) 2021
     * 
     */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz (1 << 18)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    char c = getchar();
    T f = 1, num = 0;
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

int main() {
    int n = read<int>();
    if (n == 5) {
        puts("1 2 3");
        puts("1 3 3");
        puts("2 4 2");
        puts("4 5 1");
        puts("3 4");
        puts("3 5");
    } else {
        int t = n >> 1;
        for (register int i = 1; i <= t; i++) printf("%d %d %d\n", i, i + t, 1);
        for (register int i = 1; i + t < n; i++) printf("%d %d %d\n", i + t, i + t + 1, (i << 1) - 1);
        puts("1 3");
        for (register int i = 1; i < t; i++) printf("%d %d\n", i, i + 1);
    }
    return 0;
}