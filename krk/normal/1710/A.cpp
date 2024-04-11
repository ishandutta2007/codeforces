#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, m, k;
int a[Maxn];

bool Solve(int w, int h)
{
    if (w == 1) {
        for (int i = 0; i < k; i++)
            if (a[i] >= h) return true;
        return false;
    }
    int nd = w;
    bool canbeodd = false;
    for (int i = 0; i < k; i++) {
        int add = a[i] / h;
        if (add > 1) {
            if (nd > 0) nd -= add;
            if (add >= 3) canbeodd = true;
        }
    }
    return nd <= 0 && (w % 2 == 0 || canbeodd);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < k; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Solve(n, m) || Solve(m, n)? "Yes": "No");
    }
    return 0;
}