#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n,a[maxn];
void work() {
    scanf("%d", &n);
    int mx[2] = {0, 0};
    bool flg = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (mx[a[i] & 1] > a[i]) flg = 0;
        mx[a[i] & 1] = max(mx[a[i] & 1], a[i]);
    }
    printf(flg ? "Yes\n" : "No\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) work();
	return 0;
}