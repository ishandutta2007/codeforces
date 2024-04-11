#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int n, k;
int N;
int c[Maxn];
int rem[Maxn];
int lst[Maxn];
bool tk[Maxn];
int lim;
int res1[Maxn], res2[Maxn];

bool Write(int a, int b)
{
    for (int i = a; i <= b; i++)
        if (!rem[i]) return false;
    for (int i = a; i <= b; i++)
        rem[i]--;
    return true;
}

int main()
{
    scanf("%d %d", &n, &k);
    N = n * k;
    lim = (n - 1) / (k - 1) + 1;
    for (int i = 0; i < N; i++) {
        scanf("%d", &c[i]);
        rem[i] = lim;
    }
    fill(lst, lst + n + 1, -1);
    for (int i = 0; i < N; i++) if (!tk[c[i]]) {
        if (lst[c[i]] != -1)
            if (Write(lst[c[i]], i)) {
                tk[c[i]] = true;
                res1[c[i]] = lst[c[i]];
                res2[c[i]] = i;
            }
        lst[c[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", res1[i] + 1, res2[i] + 1);
    return 0;
}