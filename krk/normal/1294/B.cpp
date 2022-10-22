#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int T;
int n;
ii xy[Maxn];

void Solve()
{
    int curx = 0, cury = 0;
    string s;
    for (int i = 0; i < n; i++) {
        if (curx < xy[i].first) { s += string(xy[i].first - curx, 'R'); curx = xy[i].first; }
        if (cury > xy[i].second) { printf("NO\n"); return; }
        if (cury < xy[i].second) { s += string(xy[i].second - cury, 'U'); cury = xy[i].second; }
    }
    printf("YES\n");
    printf("%s\n", s.c_str());
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &xy[i].first, &xy[i].second);
        sort(xy, xy + n);
        Solve();
    }
    return 0;
}