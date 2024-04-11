#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 20005;

int n, t[Maxn];
int res = -Inf;

int getRes(int d)
{
    int res = -Inf;
    for (int i = 0; i < d; i++) {
        int cand = 0;
        for (int j = i; j < n; j += d) cand += t[j];
        res = max(res, cand);
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            if (i >= 3) res = max(res, getRes(n / i));
            if (n / i >= 3) res = max(res, getRes(i));
        }
    printf("%d\n", res);
    return 0;
}