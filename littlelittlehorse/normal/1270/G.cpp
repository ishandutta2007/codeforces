#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, a[1000001], c[1000001], cnt; 
bool b[1000001];

int main() {
    scanf("%d", &test);
    for (; test--;) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] = i - a[i];
            b[i] = false;
        }
        cnt = 0;
        c[++cnt] = 1; b[1] = true; 
        int i = a[1];
        for (; !b[i]; i = a[i])
            c[++cnt] = i, b[i] = true;
        c[++cnt] = i;
        int len = 1;
        for (int i = cnt - 1; i; --i)
            if (c[i] == c[cnt])
                break;
            else
                ++len;
        printf("%d\n%d", len, c[cnt]);
        for (int i = cnt - 1; i; --i)
            if (c[i] == c[cnt])
                break;
            else
                printf(" %d", c[i]);
        printf("\n");
    }   
}