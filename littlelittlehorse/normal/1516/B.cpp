#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int test, n, a[2001];
bool b[2001];
set<int> c;

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            a[i] ^= a[i - 1];
        c.clear();
        bool ok = false;
        for (int i = 1; i < n && !ok; i++) {
            c.clear();
            c.insert(a[i]);
            int p = i;
            for (int j = i; j <= n; j++)
                if (c.find(a[j] ^ a[i]) != c.end()) {
                    c.insert(a[j]);
                    p = j;
                }
            if (p == n) {
                ok = true;
            }
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
}