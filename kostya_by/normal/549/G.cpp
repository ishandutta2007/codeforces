#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 200200;

int n;
int a[MAXN];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i] );
        a[i] += i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        a[i] -= i;
        if (i > 0 && a[i] < a[i - 1] ) {
            printf(":(\n");
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i] );
    }
    printf("\n");
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}