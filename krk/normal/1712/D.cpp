#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int lim = 1000000000;
const int Maxn = 100005;

int T;
int n, k;
int a[Maxn];
int rl[Maxn];

bool Check1(int x)
{
    int nd = 0;
    for (int i = 0; i < n; i++)
        nd += a[i] < x;
    return nd <= k;
}

bool checkNoLeft(int x)
{
    for (int i = 0; i + 1 < n; i++)
        if (min(rl[i], rl[i + 1]) >= x) return true;
    return false;
}

bool checkOneLeft(int x)
{
    for (int i = 0; i + 1 < n; i++)
        if (max(rl[i], rl[i + 1]) >= x) return true;
    return false;
}

bool Check2(int x)
{
    int lft = k;
    int hf = (x + 1) / 2;
    for (int i = 0; i < n; i++)
        if (a[i] < hf) { rl[i] = lim; lft--; }
        else rl[i] = a[i];
    if (lft < 0) return false;
    if (lft >= 2) return true;
    return lft == 0? checkNoLeft(x): checkOneLeft(x);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int lef = 0, rig = 1000000000;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Check1(mid) || Check2(mid)) lef = mid + 1;
            else rig = mid - 1;
        }
        printf("%d\n", rig);
    }
    return 0;
}