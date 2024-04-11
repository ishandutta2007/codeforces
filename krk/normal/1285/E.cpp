#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
ii p[Maxn];
int pref[Maxn], lst[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i].first, &p[i].second);
        sort(p, p + n);
        pref[0] = 1, lst[0] = p[0].second;
        for (int i = 1; i < n; i++)
            if (p[i].first <= lst[i - 1]) {
                pref[i] = pref[i - 1];
                lst[i] = max(p[i].second, lst[i - 1]);
            } else {
                pref[i] = pref[i - 1] + 1;
                lst[i] = p[i].second;
            }
        int res = 0;
        vector <ii> S;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) res = max(res, pref[i - 1]);
            else if (i == 0) res = max(res, int(S.size()));
            else {
                int l = 1, r = int(S.size());
                while (l <= r) {
                    int m = l + r >> 1;
                    int ind = int(S.size()) - m;
                    if (S[ind].first <= lst[i - 1]) l = m + 1;
                    else r = m - 1;
                }
                res = max(res, pref[i - 1] + int(S.size()) - (l - 1));
            }
            while (!S.empty() && S.back().first <= p[i].second) {
                p[i].second = max(p[i].second, S.back().second);
                S.pop_back();
            }
            S.push_back(p[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}