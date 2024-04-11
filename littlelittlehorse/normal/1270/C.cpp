#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, a[1001][3];

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d", &n);
        long long x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            int z;
            scanf("%d", &z);
            x += z; 
            y ^= z;
        }
        printf("3\n%I64d %I64d %I64d\n", y, 0LL, x + y);
    }    
}