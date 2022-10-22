#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int best[Maxn];
vector <int> un;
vector <int> my[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        un.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            un.push_back(a[i]);
        }
        sort(un.begin(), un.end());
        un.erase(unique(un.begin(), un.end()), un.end());
        for (int i = 0; i < un.size(); i++)
            my[i].clear();
        for (int i = 0; i < n; i++) {
            int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
            my[ind].push_back(i);
        }
        int res = 0;
        for (int i = 0; i < un.size(); i++)
            res = max(res, int(my[i].size()));
        for (int i = 0; i + 1 < un.size(); i++) {
            best[i] = my[i + 1].size();
            int a = 0, b = 0;
            while (a < my[i].size() || b < my[i + 1].size()) {
                if (a < my[i].size() && (b >= my[i + 1].size() || my[i][a] < my[i + 1][b]))
                    a++;
                else b++;
                best[i] = max(best[i], a + int(my[i + 1].size()) - b);
            }
            res = max(res, best[i]);
        }
        int l = 0, add = 0;
        for (int r = 0; r < un.size(); r++) {
            if (r > 0 && my[r - 1].back() > my[r][0]) { l = r; add = 0; }
            add += my[r].size();
            int cand = add;
            if (l > 0) cand += best[l - 1] - my[l].size();
            if (r + 1 < un.size()) cand += best[r] - my[r].size();
            res = max(res, cand);
        }
        printf("%d\n", n - res);
    }
    return 0;
}