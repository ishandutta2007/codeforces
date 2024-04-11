#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int q;
int n;
ii tk[Maxn];

bool Less(const ii &a, const ii &b)
{
    return a.second < b.second;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            tk[i] = ii(-1, -1);
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            if (tk[a].first == -1) tk[a] = ii(i, i);
            else tk[a].second = i;
        }
        vector <ii> seq;
        for (int i = 1; i <= n; i++) if (tk[i].first != -1)
            seq.push_back(tk[i]);
        int best = 0;
        int i = 0;
        while (i < seq.size()) {
            int lst = seq[i].second;
            int j = i + 1;
            while (j < seq.size() && lst < seq[j].first) {
                lst = seq[j].second;
                j++;
            }
            best = max(best, j - i);
            i = j;
        }
        int res = int(seq.size()) - best;
        printf("%d\n", res);
    }
    return 0;
}