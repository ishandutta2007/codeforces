#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;

int a, b;
ll res;
int bi;

void Check(int d)
{
    int na = ((a - 1) / d + 1) * d;
    int k = na - a;
    ll cand = ll(a + k) / ll(d) * ll(b + k);
    if (cand < res || cand == res && k < bi) { res = cand; bi = k; }
}

int main()
{
    scanf("%d %d", &a, &b);
    if (a > b) swap(a, b);
    int d = b - a;
    if (d == 0) printf("0\n");
    else {
        res = Inf, bi = -1;
        for (int i = 1; i * i <= d; i++) if (d % i == 0) {
            Check(i);
            Check(d / i);
        }
        printf("%d\n", bi);
    }
    return 0;
}