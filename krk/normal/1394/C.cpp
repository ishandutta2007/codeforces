#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;

int n;
char str[Maxn];
ii p[Maxn];

ii Get(int dif)
{
    int Lx = 0, Rx = Maxn;
    int Ly = 0, Ry = Maxn;
    int Ld = -Maxn, Rd = Maxn;
    for (int i = 0; i < n; i++) {
        Lx = max(Lx, p[i].first - dif);
        Rx = min(Rx, p[i].first + dif);
        Ly = max(Ly, p[i].second - dif);
        Ry = min(Ry, p[i].second + dif);
        Ld = max(Ld, p[i].first - p[i].second - dif);
        Rd = min(Rd, p[i].first - p[i].second + dif);
    }
    for (int x = Lx; x <= Rx; x++) {
        int L = Ly, R = Ry;
        if (x == 0) L = max(L, 1);
        L = max(L, x - Rd); R = min(R, x - Ld);
        if (L <= R) return ii(x, L);
    }
    return ii(-1, -1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int slen = strlen(str);
        for (int j = 0; j < slen; j++)
            if (str[j] == 'B') p[i].first++;
            else p[i].second++;
    }
    int lef = 0, rig = Maxn;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Get(mid).first != -1) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d\n", lef);
    ii res = Get(lef);
    if (res.first) printf("%s", string(res.first, 'B').c_str());
    if (res.second) printf("%s", string(res.second, 'N').c_str());
    printf("\n");
    return 0;
}