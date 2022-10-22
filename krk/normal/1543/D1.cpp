#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;

int Ask(int x)
{
    printf("%d\n", x); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (Ask(cur ^ i)) break;
            else cur = (cur ^ i) ^ cur;
        }
    }
    return 0;
}