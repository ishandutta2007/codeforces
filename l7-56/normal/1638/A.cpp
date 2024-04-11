#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 510;
int n,a[maxn], pos[maxn];
void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pos[a[i]] = i;
    int x = 1;
    while (x < n && a[x] == x) ++x;
    reverse(a + x, a + pos[x] + 1);
    for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) work();
	return 0;
}