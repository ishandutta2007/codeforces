#include <bits/stdc++.h>
using namespace std;

const int Maxl = 24;
const int Maxs = 5;

int n;
char tmp[Maxs];
int has[1 << Maxl];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        int mask = (1 << Maxl) - 1;
        for (int j = 0; j < 3; j++) {
            int let = tmp[j] - 'a';
            if (mask & 1 << let)
                mask ^= 1 << let;
        }
        has[mask]++;
    }
    for (int b = 0; b < Maxl; b++)
        for (int i = 0; i < 1 << Maxl; i++)
            if (i & 1 << b)
                has[i ^ (1 << b)] += has[i];
    for (int i = 0; i < 1 << Maxl; i++) {
        int ans = n - has[i];
        res ^= ans * ans;
    }
    printf("%d\n", res);
    return 0;
}