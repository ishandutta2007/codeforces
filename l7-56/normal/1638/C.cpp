#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 +10;
int n,a[maxn],mn[maxn],tp;
void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    tp = 0;
    for (int i = n; i >= 1; --i) {
        int val = a[i];
        while (tp && mn[tp] < a[i]) val = min(val, mn[tp--]);
        mn[++tp] = val;
    }
    printf("%d\n", tp);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) work();
	return 0;
}