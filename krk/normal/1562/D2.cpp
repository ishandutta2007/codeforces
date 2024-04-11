#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int T;
int n, q;
char str[Maxn];
int seq[Maxn];
int a[Maxn];
map <ii, vector <int> > M;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        scanf("%s", str + 1);
        M.clear();
        for (int i = 1; i <= n; i++) {
            seq[i] = ((str[i] == '+') ^ (i % 2 != 0))? 1: -1;
            a[i] = a[i - 1] + seq[i];
            M[ii(a[i], seq[i])].push_back(i);
        }
        for (int i = 0; i < q; i++) {
            int l, r; scanf("%d %d", &l, &r);
            int dif = a[r] - a[l - 1];
            if (dif == 0) { printf("0\n"); continue; }
            vector <int> res;
            if (dif % 2 == 0) {
                dif -= seq[r];
                res.push_back(r);
                r--;
            }
            ii lf = dif > 0? ii(a[l - 1] + (dif + 1) / 2, 1): ii(a[l - 1] + (dif - 1) / 2, -1);
            auto it = M.find(lf);
            int ind = lower_bound(it->second.begin(), it->second.end(), l) - it->second.begin();
            res.push_back(it->second[ind]);
            sort(res.begin(), res.end());
            printf("%d\n", int(res.size()));
            for (int i = 0; i < res.size(); i++)
                printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
        }
    }
    return 0;
}