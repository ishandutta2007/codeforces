#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

ii p[6];

bool Ok(int x, int y)
{
    if (p[2].first <= x && x <= p[3].first &&
        p[2].second <= y && y <= p[3].second) return false;
    if (p[4].first <= x && x <= p[5].first &&
        p[4].second <= y && y <= p[5].second) return false;
    return true;
}

int main()
{
    for (int i = 0; i < 6; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        p[i].first *= 2; p[i].second *= 2;
    }
    for (int i = p[0].first; i <= p[1].first; i++)
        if (Ok(i, p[0].second) || Ok(i, p[1].second)) {
            printf("YES\n"); return 0;
        }
    for (int j = p[0].second; j <= p[1].second; j++)
        if (Ok(p[0].first, j) || Ok(p[1].first, j)) {
            printf("YES\n"); return 0;
        }
    printf("NO\n");
    return 0;
}