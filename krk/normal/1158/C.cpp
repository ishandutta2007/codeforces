#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int T;
int n;
int nxt[Maxn];
vector <int> my[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n + 1; i++) {
            res[i] = 0; my[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &nxt[i]);
            if (nxt[i] != -1) my[nxt[i]].push_back(i);
        }
        vector <int> S;
        int cur = n + 1;
        bool ok = true;
        for (int i = n + 1; i > 0; i--) {
            if (res[i] == 0) res[i] = cur--;
            for (int j = 0; j < my[i].size(); j++) {
                int ind = my[i][j];
                res[ind] = cur--;
            }
            if (i <= n) {
                while (!S.empty() && res[i] > res[S.back()])
                    S.pop_back();
                int should = S.empty()? n + 1: S.back();
                if (nxt[i] != -1 && nxt[i] != should)
                    ok = false;
                S.push_back(i);
            }
        }
        if (ok)
            for (int i = 1; i <= n; i++)
                printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
        else printf("-1\n");
    }
    return 0;
}