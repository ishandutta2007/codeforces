#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2050;

int T;
int n;
int a[Maxn];
vector <int> res;

void Reverse(int r)
{
    res.push_back(r);
    for (int i = 1, j = r; i < j; i++, j--)
        swap(a[i], a[j]);
}

ii getInds(int n)
{
    int ind = 1;
    while (a[ind] != n - 1) ind++;
    int ind2 = 1;
    while (a[ind2] != n) ind2++;
    return ii(ind, ind2);
}

void Solve(int n)
{
    if (a[n] == n && a[n - 1] == n - 1) return;
    ii inds = getInds(n);
    if (abs(inds.first - inds.second) > 1) {
        Reverse(inds.second);
        inds = getInds(n);
        Reverse(inds.first - 1);
        inds = getInds(n);
    }
    if (inds.second < inds.first) {
        Reverse(inds.first + 1);
        inds = getInds(n);
    }
    Reverse(inds.second);
    Reverse(n);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool fall = false;
        res.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] % 2 != i % 2) fall = true;
        }
        if (fall) { printf("-1\n"); continue; }
        for (int i = n; i > 1; i -= 2)
            Solve(i);
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}