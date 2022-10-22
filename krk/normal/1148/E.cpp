#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 300005;

int n;
ii s[Maxn], t[Maxn];
int d[Maxn];
vector <iii> res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i].first);
        s[i].second = i + 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i].first);
        t[i].second = i + 1;
    }
    sort(s, s + n);
    sort(t, t + n);
    for (int i = 0; i < n; i++)
        d[i] = t[i].first - s[i].first;
    int pnt = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] < 0) { printf("NO\n"); return 0; }
        pnt = max(i + 1, pnt);
        while (d[i] > 0) {
            while (pnt < n && d[pnt] >= 0) pnt++;
            if (pnt >= n) break;
            int tk = min(d[i], -d[pnt]);
            res.push_back(iii(ii(s[i].second, s[pnt].second), tk));
            d[i] -= tk; d[pnt] += tk;
        }
        if (d[i] > 0) { printf("NO\n"); return 0; }
    }
    printf("YES\n");
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
    return 0;
}