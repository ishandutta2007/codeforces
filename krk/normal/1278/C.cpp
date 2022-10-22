#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int t;
int n;
int a[Maxn];
map <int, int> A;

int Get(int x)
{
    auto it = A.find(x);
    return it == A.end()? Maxn: it->second;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        A.clear();
        int st = 0;
        for (int i = 0; i < 2 * n; i++)
            scanf("%d", &a[i]);
        A[st] = n;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) st++;
            else st--;
            A[st] = n - 1 - i;
        }
        st = 0;
        int res = n + Get(st);
        for (int i = 2 * n - 1; i >= n; i--) {
            if (a[i] == 1) st--;
            else st++;
            res = min(res, i - n + Get(st));
        }
        printf("%d\n", res);
    }
    return 0;
}