#include <bits/stdc++.h>
using namespace std;

const int Maxm = 52;
const int Maxn = 10005;

int m, n;
int freq[Maxm][Maxn];

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            int a; scanf("%d", &a);
            freq[i][a]++;
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++) {
            bool found = false;
            for (int k = 1; k <= n && !found; k++)
                found = freq[i][k] > 0 && freq[j][k] > 0;
            if (!found) { printf("impossible\n"); return 0; }
        }
    printf("possible\n");
    return 0;
}