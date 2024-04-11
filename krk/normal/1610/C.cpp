#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn], b[Maxn];

bool Solve(int x)
{
    int got = 0;
    for (int i = 0; i < n; i++) {
        int my = min(got, a[i]) + 1;
        if (x - my <= b[i]) got = max(got, my);
    }
    return got >= x;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &b[i], &a[i]);
        int lef = 0, rig = n;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Solve(mid)) lef = mid + 1;
            else rig = mid - 1;
        }
        printf("%d\n", rig);
    }
    return 0;
}