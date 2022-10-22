#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 6;
const int Maxm = 100005;

int a[Maxn];
int m;
int b[Maxm];
int my[Maxm];
set <ii> S;
int res = 2000000007;

int main()
{
    for (int i = 0; i < Maxn; i++)
        scanf("%d", &a[i]);
    sort(a, a + Maxn);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        my[i] = Maxn - 1;
        S.insert(ii(b[i] - a[my[i]], i));
    }
    while (true) {
        res = min(res, S.rbegin()->first - S.begin()->first);
        ii p = *S.begin();
        S.erase(S.begin());
        my[p.second]--;
        if (my[p.second] < 0) break;
        S.insert(ii(b[p.second] - a[my[p.second]], p.second));
    }
    printf("%d\n", res);
    return 0;
}