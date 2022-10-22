#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
ii A[Maxn], B[Maxn];

bool Check(int ind)
{
    int pnt = 1;
    for (int i = 1; i <= n; i++) if (i != ind)
        B[pnt++] = A[i];
    for (int i = 3; i <= n - 1; i++)
        if (B[i].first - B[i - 1].first != B[2].first - B[1].first) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i].first);
        A[i].second = i;
    }
    sort(A + 1, A + n + 1);
    if (Check(1)) { printf("%d\n", A[1].second); return 0; }
    if (Check(2)) { printf("%d\n", A[2].second); return 0; }
    int d = A[2].first - A[1].first;
    for (int i = 3; i <= n; i++)
        if (A[i].first - A[i - 1].first != A[2].first - A[1].first)
            if (Check(i)) { printf("%d\n", A[i].second); return 0; }
            else { printf("-1\n"); return 0; }
    printf("-1\n");
    return 0;
}