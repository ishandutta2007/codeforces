#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int p[Maxn];
int c[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = Maxn;
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        for (int i = 1; i <= n; i++) if (p[i]) {
            vector <int> seq;
            int cur = i;
            while (p[cur]) {
                seq.push_back(cur);
                int nxt = p[cur]; p[cur] = 0;
                cur = nxt;
            }
            for (int j = 1; j <= seq.size(); j++) if (seq.size() % j == 0)
                for (int k = 0; k < j; k++) {
                    bool ok = true;
                    for (int z = k + j; z < seq.size() && ok; z += j)
                        ok = c[seq[k]] == c[seq[z]];
                    if (ok) res = min(res, j);
                }
        }
        printf("%d\n", res);
    }
    return 0;
}