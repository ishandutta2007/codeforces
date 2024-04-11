#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int f[3];
int a[Maxn];

int main()
{
    scanf("%d", &n);
    while (n--) {
        int a; scanf("%d", &a);
        f[a]++;
    }
    int len = 0;
    if (f[1] > 0 && f[2] > 0) {
        a[len++] = 2; f[2]--;
        a[len++] = 1; f[1]--;
    }
    while (f[2] > 0) {
        a[len++] = 2; f[2]--;
    }
    while (f[1] > 0) {
        a[len++] = 1; f[1]--;
    }
    for (int i = 0; i < len; i++)
        printf("%d%c", a[i], i + 1 < len? ' ': '\n');
    return 0;
}