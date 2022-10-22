#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if (a[0] != n && a[n - 1] != n) { printf("-1\n"); continue; }
        deque <int> D;
        int lef = 0, rig = n - 1;
        while (lef <= rig)
            if (a[lef] >= a[rig])
                D.push_front(a[lef++]);
            else D.push_back(a[rig--]);
        for (int i = 0; i < D.size(); i++)
            printf("%d%c", D[i], i + 1 < D.size()? ' ': '\n');
    }
    return 0;
}