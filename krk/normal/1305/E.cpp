#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> res;

int main()
{
    scanf("%d %d", &n, &m);
    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx += (i - 1) / 2;
    if (mx < m) { printf("-1\n"); return 0; }
    for (int i = 1; i <= n; i++)
        if ((i - 1) / 2 <= m) {
            res.push_back(i);
            m -= (i - 1) / 2;
        }
    if (m > 0) {
        for (int i = res.back() + 1; ; i++) {
            int my = 0;
            for (int j = 0; j < res.size(); j++) {
                int nd = i - res[j];
                if (res[j] < nd && nd <= res.back())
                    my++;
            }
            if (my == m) { res.push_back(i); break; }
        }
    }
    int nd = n - int(res.size());
    for (int i = 1; i <= nd; i++)
        res.push_back(1000000000 - 3 * i * n);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}