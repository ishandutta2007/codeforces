#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, p;
vector <ii> el[Maxn];
int a[Maxn];
vector <int> res;

int main()
{
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int mx = 1, mn = a[n];
    for (int i = n; i > 0; i--) {
        mx = max(mx, a[i] - i + 1);
        ii my = ii(a[i] - i + p, a[i] - i + i / p * p);
        if (my.first <= my.second) {
            int ind = (a[i] - i) % p;
            if (ind < 0) ind += p;
            el[ind].push_back(my);
        }
        if (i % p == 0) mn = min(mn, a[i] - 1);
    }
    for (int i = 0; i < p; i++) {
        vector <ii> tmp;
        sort(el[i].begin(), el[i].end());
        for (int j = 0; j < el[i].size(); j++)
            if (tmp.empty() || tmp.back().second < el[i][j].first)
                tmp.push_back(el[i][j]);
            else tmp.back().second = max(tmp.back().second, el[i][j].second);
        el[i] = tmp;
    }
    for (int i = a[n]; i > a[n] - n; i--) if (i >= mx && i <= mn) {
        int ind = i % p;
        while (!el[ind].empty() && i < el[ind].back().first) el[ind].pop_back();
        if (el[ind].empty() || i > el[ind].back().second) res.push_back(i);
    }
    printf("%d\n", int(res.size()));
    for (int i = int(res.size()) - 1; i >= 0; i--)
        printf("%d%c", res[i], i - 1 >= 0? ' ': '\n');
    return 0;
}