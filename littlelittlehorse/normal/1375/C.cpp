#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[1000001], c[1000001];

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int cnt = 0;
        for (int i = n; i; --i) {
            if (!cnt || a[i] > c[cnt])
                c[++cnt] = a[i];
            else {
                for (; cnt && a[i] < c[cnt]; --cnt);
                ++cnt;
            }
        }
        if (cnt == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}