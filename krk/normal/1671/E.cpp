#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 18;
const int mod = 998244353;

int n;
char str[Maxn + 5];
string my[Maxn + 5];
int res = 1;

void Solve(int v)
{
    if (v * 2 >= 1 << n) {
        my[v] = str[v];
        return;
    }
    int lc = 2 * v, rc = 2 * v + 1;
    Solve(lc);
    Solve(rc);
    if (my[lc] == my[rc]) my[v] = str[v] + my[lc] + my[rc];
    else {
        if (my[lc] > my[rc]) swap(my[lc], my[rc]);
        my[v] = str[v] + my[lc] + my[rc];
        res = 2 * res % mod;
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str + 1);
    Solve(1);
    printf("%d\n", res);
    return 0;
}