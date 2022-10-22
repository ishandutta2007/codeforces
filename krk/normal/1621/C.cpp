#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
int n;
bool tk[Maxn];
int res[Maxn];

int Ask(int v)
{
    printf("? %d\n", v); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(tk, tk + n + 1, false);
        for (int i = 1; i <= n; i++) if (!tk[i]) {
            int mem = Ask(i);
            int v = mem;
            do {
                tk[v] = true;
                int u = Ask(i);
                res[v] = u;
                v = u;
            } while (v != mem);
        }
        printf("!");
        for (int i = 1; i <= n; i++)
            printf(" %d", res[i]);
        printf("\n"); fflush(stdout);
    }
    return 0;
}