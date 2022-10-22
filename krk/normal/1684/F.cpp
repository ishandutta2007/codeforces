#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n, m;
int a[Maxn];
int tolef[Maxn];
map <int, vector <int> > M;
ii L[Maxn], R[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            tolef[i] = i;
            L[i] = ii(n + 1, 0);
            R[i] = ii(n + 1, 0);
        }
        for (int i = 1; i <= m; i++) {
            int l, r; scanf("%d %d", &l, &r);
            tolef[r] = min(tolef[r], l);
        }
        for (int i = n - 1; i > 0; i--)
            tolef[i] = min(tolef[i], tolef[i + 1]);
        bool was = false;
        M.clear();
        for (int i = 1; i <= n; i++) {
            M[a[i]].push_back(i);
            auto it = M.find(a[i]);
            int myrig = int(it->second.size()) - 1;
            int mylef = lower_bound(it->second.begin(), it->second.end(), tolef[i]) - it->second.begin();
            if (mylef < myrig) {
                was = true;
                L[it->second[mylef]].first = min(L[it->second[mylef]].first, it->second[mylef + 1]);
                L[it->second[mylef]].second = max(L[it->second[mylef]].second, it->second[myrig]);
                R[it->second[mylef]].first = min(R[it->second[myrig]].first, it->second[mylef]);
                R[it->second[mylef]].second = max(R[it->second[myrig]].second, it->second[myrig - 1]);
            }
        }
        if (!was) { printf("0\n"); continue; }
        L[0] = ii(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            L[i].first = min(L[i].first, L[i - 1].first);
            L[i].second = max(L[i].second, L[i - 1].second);
        }
        R[n + 1] = ii(n + 1, 0);
        for (int i = n; i > 0; i--) {
            R[i].first = min(R[i].first, R[i + 1].first);
            R[i].second = max(R[i].second, R[i + 1].second);
        }
        int res = n;
        for (int i = 1; i <= n; i++) {
            int mylef = min(min(L[i - 1].first, R[i].first), i);
            int myrig = max(max(L[i - 1].second, R[i].second), i);
            res = min(res, myrig - mylef + 1);
        }
        printf("%d\n", res);
    }
    return 0;
}