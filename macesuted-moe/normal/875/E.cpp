/**
 * @author Macesuted
 * @date 2021-01-07
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
    T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c)) {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define maxn 100005

int x[maxn];
int n, s1, s2;

bool check(int far) {
    static set<int> S;
    S.clear();
    S.insert(s1), S.insert(s2);
    for (register int i = 1; i <= n; i++) {
        while (S.size() && abs(*S.begin() - x[i]) > far) S.erase(S.begin());
        while (S.size() && abs(*S.rbegin() - x[i]) > far) S.erase(--S.end());
        if (S.empty()) return false;
        S.insert(x[i]);
    }
    return true;
}

int main() {
    n = read<int>(), s1 = read<int>(), s2 = read<int>();
    for (register int i = 1; i <= n; i++) x[i] = read<int>();
    int l = abs(s1 - s2), r = 1000000005;
    while (l < r) {
        int mid = (l + r) >> 1;
        check(mid) ? r = mid : l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}