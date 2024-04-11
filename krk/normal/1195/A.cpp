#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, k;
int freq[Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        freq[a]++;
    }
    int lft = (n + 1) / 2;
    for (int i = 1; i <= k; i++) {
        lft -= freq[i] / 2; res += freq[i] / 2 * 2;
        freq[i] %= 2;
    }
    for (int i = 1; i <= k; i++)
        if (freq[i] > 0 && lft > 0) { freq[i]--; res++; lft--; }
    printf("%d\n", res);
    return 0;
}