#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int T;
int n;
vector <int> V[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            V[i].clear();
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            V[a].push_back(i);
        }
        vector <iii> seq;
        for (int i = 1; i <= n; i++) if (!V[i].empty())
            seq.push_back(iii(ii(V[i][0], V[i].back()), i));
        sort(seq.begin(), seq.end());
        int res = 0;
        int lst = 0;
        vector <iii> S;
        for (int i = 0; i < seq.size(); i++) {
            if (!S.empty() && (S.back().second > seq[i].second || S.back().first.second >= seq[i].first.first)) {
                for (int j = 0; j < S.size(); j++) {
                    res++;
                    lst = max(lst, S[j].first.second);
                }
                S.clear();
            }
            if (lst >= seq[i].first.first) {
                res++;
                lst = max(lst, seq[i].first.second);
            } else S.push_back(seq[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}