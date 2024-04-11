#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 1000005;

int n;
char str[Maxn];
int my[Maxn];
int to[Maxn];

int Get(int x, int len)
{
    if (x >= n || my[x] >= len) return x;
    return to[x] = Get(to[x], len);
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    int zer = n, one = n;
    for (int i = n - 1; i >= 0; i--) {
        to[i] = i + 1;
        if (str[i] == '?') my[i] = my[i + 1] + 1;
        else if (str[i] == '0') { my[i] = one - i; zer = i; }
        else { my[i] = zer - i; one = i; }
    }
    for (int i = 1; i <= n; i++) {
        int cur = Get(0, i);
        int res = 0;
        while (cur < n) {
            res++;
            cur = Get(cur + i, i);
        }
        printf("%d%c", res, i + 1 <= n? ' ': '\n');
    }
    return 0;
}