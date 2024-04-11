#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 300005;

int T;
int n, m;
int a[Maxn];
vector <int> un;
set <ii> forb;
int cnt[Maxn];
vector <int> seq;
vector <vector <int> > best;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        un.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            un.push_back(a[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        forb.clear();
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            forb.insert(ii(a, b));
            forb.insert(ii(b, a));
        }
        fill(cnt, cnt + n + 1, 0);
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
            cnt[a[i]]++;
        }
        seq.clear(); best.clear();
        for (int i = 0; i < un.size(); i++)
            seq.push_back(cnt[i]);
        sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
        best.resize(seq.size());
        for (int i = 0; i < un.size(); i++) {
            int ind = lower_bound(seq.begin(), seq.end(), cnt[i]) - seq.begin();
            best[ind].push_back(un[i]);
        }
        ll res = 0;
        for (int i = 0; i < best.size(); i++)
            for (int j = i; j < best.size(); j++) {
                set <iii> S;
                S.insert(iii(best[i].back() + best[j].back(), ii(int(best[i].size()) - 1, int(best[j].size()) - 1)));
                set <iii>::iterator it;
                while (!S.empty()) {
                    it = S.end(); it--;
                    ii p = it->second;
                    if (best[i][p.first] == best[j][p.second] || forb.find(ii(best[i][p.first], best[j][p.second])) != forb.end()) {
                        if (p.first > 0) S.insert(iii(best[i][p.first - 1] + best[j][p.second], ii(p.first - 1, p.second)));
                        if (p.second > 0) S.insert(iii(best[i][p.first] + best[j][p.second - 1], ii(p.first, p.second - 1)));
                        S.erase(it);
                    } else {
                        res = max(res, ll(seq[i] + seq[j]) * it->first);
                        break;
                    }
                }
            }
        printf("%I64d\n", res);
    }
    return 0;
}