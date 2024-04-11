#include <cstdio>
#include <algorithm>

using namespace std;

int n, c, x[105];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &c);
    for (int i=0; i<n; i++) scanf("%d", &x[i]);

    int ans = 0;
    for (int i=0; i<n-1; i++)
        ans = max(ans, x[i] - x[i+1] - c);

    printf("%d\n", ans);
    return 0;
}