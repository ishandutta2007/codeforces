#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[300001], f[300001], Left, c[300001];

inline void insert(int x) {
    for (; x <= n; x += x & (-x))
        ++f[x];
}

int calc(int x) {
    int will = 0;
    for (; x; x -= x & (-x))
        will += f[x];
    return will;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(f, 0, sizeof(f));
    memset(c, 0, sizeof(c));
    Left = n;
    printf("1");
    for (int i = 1; i <= n; i++)
    {
        c[a[i]] = 1;
        insert(a[i]);
        for (; Left && c[Left]; --Left);
        printf(" %d", calc(Left) + 1);
    }
    printf("\n");
}