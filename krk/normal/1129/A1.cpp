#include <bits/stdc++.h>
using namespace std;

const int Maxn = 20005;

int n, m;
vector <int> my[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        int tk = b - a;
        if (tk < 0) tk += n;
        my[a].push_back(tk);
    }
    for (int i = 1; i <= n; i++)
        sort(my[i].begin(), my[i].end());
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) if (!my[j].empty()) {
            int cand = j - i;
            if (cand < 0) cand += n;
            cand += (int(my[j].size()) - 1) * n + my[j][0];
            mx = max(mx, cand);
        }
        printf("%d%c", mx, i + 1 <= n? ' ': '\n');
    }
    return 0;
}