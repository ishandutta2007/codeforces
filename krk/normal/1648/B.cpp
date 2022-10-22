#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int T;
int n, c;
int has[Maxn];
int sum[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &c);
        fill(has, has + c + 1, 0);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            has[a]++;
        }
        for (int i = 1; i <= c; i++)
            sum[i] = sum[i - 1] + has[i];
        if (!has[1]) { printf("No\n"); continue; }
        bool fall = false;
        for (int i = 2; i <= c && !fall; i++) if (has[i])
            for (int j = i; j <= c && !fall; j += i) {
                int to = min(c, j + i - 1);
                fall = sum[to] - sum[j - 1] > 0 && !has[j / i];
            }
        printf("%s\n", !fall? "Yes": "No");
    }
    return 0;
}