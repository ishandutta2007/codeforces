#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;


int n, m, k;
map <int, vector <ii> > byX, byY;
map <int, vector <ii> > nwX, nwY;
int cur;

void Solve(map <int, vector <ii> > &M, int siz, map <int, vector <ii> > &nw)
{
    for (auto it: M) {
        vector <ii> tmp;
        auto V = it.second;
        sort(V.begin(), V.end());
        for (int i = 0; i < V.size(); i++)
            if (tmp.empty() || tmp.back().second < V[i].first)
                tmp.push_back(V[i]);
            else tmp.back().second = max(tmp.back().second, V[i].second);
        int all = siz;
        for (int i = 0; i < tmp.size(); i++)
            all -= (tmp[i].second - tmp[i].first);
        cur ^= all;
        nw[it.first] = tmp;
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 == x2) byX[x1].push_back(ii(min(y1, y2), max(y1, y2)));
        else byY[y1].push_back(ii(min(x1, x2), max(x1, x2)));
    }
    if ((n - 1 - int(byX.size())) % 2) cur ^= m;
    if ((m - 1 - int(byY.size())) % 2) cur ^= n;
    Solve(byX, m, nwX);
    Solve(byY, n, nwY);
    if (cur) {
        printf("FIRST\n");
        if ((cur ^ m) < m) {
            int nd = (cur ^ m);
            int pnt = 1;
            while (pnt < n && byX.find(pnt) != byX.end()) pnt++;
            if (pnt < n) {
                printf("%d %d %d %d\n", pnt, 0, pnt, m - nd);
                return 0;
            }
        }
        if ((cur ^ n) < n) {
            int nd = (cur ^ n);
            int pnt = 1;
            while (pnt < m && byY.find(pnt) != byY.end()) pnt++;
            if (pnt < m) {
                printf("%d %d %d %d\n", 0, pnt, n - nd, pnt);
                return 0;
            }
        }
        for (auto it: nwX) {
            int all = m;
            auto V = it.second;
            for (int i = 0; i < V.size(); i++)
                all -= (V[i].second - V[i].first);
            int nd = (cur ^ all);
            if (nd < all) {
                int lft = all - nd;
                int lst = 0;
                for (int i = 0; i < V.size(); i++) {
                    int got = V[i].first - lst;
                    if (lft <= got) break;
                    lft -= got;
                    lst = V[i].second;
                }
                printf("%d %d %d %d\n", it.first, 0, it.first, lst + lft);
                return 0;
            }
        }
        for (auto it: nwY) {
            int all = n;
            auto V = it.second;
            for (int i = 0; i < V.size(); i++)
                all -= (V[i].second - V[i].first);
            int nd = (cur ^ all);
            if (nd < all) {
                int lft = all - nd;
                int lst = 0;
                for (int i = 0; i < V.size(); i++) {
                    int got = V[i].first - lst;
                    if (lft <= got) break;
                    lft -= got;
                    lst = V[i].second;
                }
                printf("%d %d %d %d\n", 0, it.first, lst + lft, it.first);
                return 0;
            }
        }
        assert(false);
    } else printf("SECOND\n");
    return 0;
}