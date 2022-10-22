#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
int in[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            in[i] = 0;
        }
        set <int> S;
        for (int i = 1; i <= n; i++) {
            int k; scanf("%d", &k);
            in[i] = k;
            for (int j = 0; j < k; j++) {
                int a; scanf("%d", &a);
                neigh[a].push_back(i);
            }
            if (in[i] == 0) S.insert(i);
        }
        int res = 0, cnt = 0;
        while (!S.empty()) {
            res++;
            int i = 1;
            while (!S.empty() && i <= *S.rbegin()) {
                auto it = S.lower_bound(i);
                i = *it;
                S.erase(it);
                cnt++;
                for (int j = 0; j < neigh[i].size(); j++) {
                    int u = neigh[i][j];
                    if (--in[u] == 0) S.insert(u);
                }
            }
        }
        printf("%d\n", cnt < n? -1: res);
    }
    return 0;
}