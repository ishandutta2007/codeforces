#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;

int e, s, n, m;
vector <ii> xt;
ii fquer[Maxn];
ii res[Maxn];
deque <iii> D;
vector <int> cur(3, 0);

int main()
{
    scanf("%d %d %d %d", &e, &s, &n, &m);
    for (int i = 0; i < n; i++) {
        int t, x; scanf("%d %d", &t, &x); t--;
        if (x <= e) xt.push_back(ii(x, t));
    }
    sort(xt.begin(), xt.end());
    for (int i = 0; i < m; i++) {
        scanf("%d", &fquer[i].first);
        fquer[i].second = i;
        res[i] = ii(-1, -1);
    }
    sort(fquer, fquer + m);
    D.push_back(iii(ii(e, e + s), 2));
    int a = int(xt.size()) - 1, b = m - 1;
    while (a >= 0 || b >= 0)
        if (a >= 0 && (b < 0 || xt[a].first >= fquer[b].first)) {
            int st = xt[a].first;
            int en = xt[a].first + s;
            if (en < D.front().first.first)
                break;
            int typ = xt[a].second;
            while (typ >= D.front().second) {
                if (D.front().first.first < en) {
                    cur[D.front().second] -= (min(en, D.front().first.second) - D.front().first.first);
                    D.front().first.first = en;
                }
                if (D.front().first.first >= D.front().first.second)
                    D.pop_front();
                else break;
            }
            if (typ == D.front().second) {
                cur[typ] += D.front().first.first - st;
                D.front().first.first = st;
                a--;
                continue;
            }
            if (typ < D.front().second)
                en = min(en, D.front().first.first);
            if (st < en) {
                cur[typ] += en - st;
                D.push_front(iii(ii(st, en), typ));
            }
            a--;
        } else {
            int st = fquer[b].first;
            int en = fquer[b].first + s;
            if (en < D.front().first.first) break;
            vector <int> cp = cur;
            int i = 0;
            while (i < D.size()) {
                if (D[i].first.first < en)
                    cp[D[i].second] -= (min(en, D[i].first.second) - D[i].first.first);
                if (en >= D[i].first.second) i++;
                else break;
            }
            res[fquer[b].second] = ii(cp[0], cp[1]);
            b--;
        }
    for (int i = 0; i < m; i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}