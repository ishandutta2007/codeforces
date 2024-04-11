#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int T;
int n, m;
char str[Maxn];
int sum[Maxn];
bool hascol[Maxn];
int hasrow[Maxn];

int Get(int ind)
{
    int res = sum[ind];
    if (ind - m > 0) res -= sum[ind - m];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        scanf("%s", str + 1);
        for (int j = 0; j < m; j++) {
            hascol[j] = false;
            hasrow[j] = 0;
        }
        int cols = 0;
        for (int i = 1; i <= n * m; i++)
            sum[i] = sum[i - 1] + int(str[i] == '1');
        for (int i = 1; i <= n * m; i++) {
            if (str[i] == '1' && !hascol[i % m]) {
                hascol[i % m] = true;
                cols++;
            }
            hasrow[i % m] += int(Get(i) > 0);
            printf("%d%c", hasrow[i % m] + cols, i + 1 <= n * m? ' ': '\n');
        }
    }
    return 0;
}