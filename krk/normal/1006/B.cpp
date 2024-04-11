#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

int n, k;
ii a[Maxn];
bool tk[Maxn];
int ans;
vector <int> res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 1; i <= k; i++) {
        ans += a[n - i].first;
        tk[a[n - i].second] = true;
    }
    int lst = -1;
    for (int i = 0; i < n; i++)
        if (tk[i]) { res.push_back(i - lst); lst = i; }
    res.back() += n - 1 - lst;
    printf("%d\n", ans);
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}