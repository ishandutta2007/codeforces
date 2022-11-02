#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, cnt, a[200001];
char str1[100011], str2[100011];

int main() {
    scanf("%d", &test);
    for ( ; test--; ) {
        scanf("%d%s%s", &n, str1 + 1, str2 + 1);
        cnt = 0;
        for (int i = 1; i <= n; i++)
            if (i != 1 && str1[i] != str1[i - 1])
                a[++cnt] = i - 1;
        int c = str1[n];
        for (int i = n; i >= 0; --i) {
            for (; i && str2[i] == c; --i);
            if (i)
                a[++cnt] = i;
            if (c == '0')
                c = '1';
            else
                c = '0';
        }
        printf("%d", cnt);
        for (int i = 1; i <= cnt; i++)
            printf(" %d", a[i]);
        printf("\n");
    }
}