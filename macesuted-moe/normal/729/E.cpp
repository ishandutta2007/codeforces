/**
 * @file B.cpp
 * @author Macesuted
 * @date 2021-02-06
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

#define maxn 200005

int record[maxn];

int main() {
    int n = read<int>(), s = read<int>();
    int cnt = 1, ans = 0;
    for (register int i = 1, d; i <= n; i++) {
        d = read<int>();
        if (i == s)
            ans = (d != 0);
        else
            record[d]++;
    }
    for (register int i = 1; cnt < n; i++) {
        cnt += record[i] ? record[i] : 1;
        ans += (record[i] == 0);
    }
    printf("%d\n", ans);
    return 0;
}