#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 1 << 18;

int n, r;
int a[Maxn];
ll sum;

void Print()
{
    ld res = ld(sum) / ld(1 << n);
    printf("%.9f\n", double(res));
}

int main()
{
    scanf("%d %d", &n, &r);
    for (int i = 0; i < 1 << n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    Print();
    while (r--) {
        int ind, x; scanf("%d %d", &ind, &x);
        sum += x - a[ind]; a[ind] = x;
        Print();
    }
    return 0;
}