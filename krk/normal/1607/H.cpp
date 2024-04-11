#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;

int T;
int n;
int a[Maxn], b[Maxn], m[Maxn];
map <int, vector <iii> > M;
int eata[Maxn], eatb[Maxn];

bool byEnd(const iii &a, const iii &b)
{
    return a.first.second < b.first.second;
}

void Set(int ind, int val)
{
    eata[ind] = a[ind] - val;
    eatb[ind] = m[ind] - eata[ind];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        M.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &a[i], &b[i], &m[i]);
            int lef = max(0, a[i] - m[i]);
            int rig = a[i] - max(0, m[i] - b[i]);
            M[a[i] + b[i] - m[i]].push_back(iii(ii(lef, rig), i));
        }
        int res = 0;
        for (auto it = M.begin(); it != M.end(); it++) {
            auto V = it->second;
            sort(V.begin(), V.end(), byEnd);
            int lst = -1;
            for (int i = 0; i < V.size(); i++) {
                if (lst < V[i].first.first) {
                    res++;
                    lst = V[i].first.second;
                }
                Set(V[i].second, lst);
            }
        }
        printf("%d\n", res);
        for (int i = 0; i < n; i++)
            printf("%d %d\n", eata[i], eatb[i]);
    }
    return 0;
}