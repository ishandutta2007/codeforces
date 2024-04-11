#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, a[100001];

int main() {
    scanf("%d", &test);
    for (;test--;) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        bool ok = true;
        int M = 1 << 30;
        for (int i = 1; i <= n; i++) {
            if (a[i] < a[i - 1]) {
                if (a[i] > M) {
                    ok = false;
                    break;
                }
            }
            else
                if (i != 1 && a[i] != a[i - 1] + 1) {
                    ok = false;
                    break;
                }
             M = min(M, a[i]);
        }
        if (ok)
            printf("Yes\n");
        else
            printf("No\n");
    }
}