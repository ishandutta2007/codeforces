#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int n;
vector <ii> res;

void Solve(int l, int r)
{
    if (l == r) return;
    int m = l + r >> 1;
    int dif = m + 1 - l;
    for (int i = 0; i < dif; i++)
        res.push_back(ii(l + i, l + i + dif));
    Solve(l, m);
    Solve(m + 1, r);
}

int main()
{
    scanf("%d", &n);
    int pw = 1;
    while (pw <= n) pw *= 2;
    pw /= 2;
    Solve(1, pw);
    if (pw < n)
        Solve(n - pw + 1, n);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}