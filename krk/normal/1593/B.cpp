#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 1000000000;

int T;
ll n;

int Get(ll n, int a, int b)
{
    int nd[] = {a, b};
    int pnt = 1;
    int res = 0;
    while (n > 0 && pnt >= 0) {
        if (n % 10 == nd[pnt]) {
            if (--pnt < 0) return res;
        } else res++;
        n /= 10;
    }
    return Inf;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &n);
        printf("%d\n", min(min(Get(n, 0, 0), Get(n, 2, 5)), min(Get(n, 5, 0), Get(n, 7, 5))));
    }
    return 0;
}