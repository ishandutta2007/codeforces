#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
map <vector <int>, int> M;
int n;
int res[Maxn];

int Ask(int a, int b, int c)
{
    vector <int> seq = {a, b, c};
    sort(seq.begin(), seq.end());
    auto it = M.find(seq);
    if (it != M.end()) return it->second;
    printf("? %d %d %d\n", a, b, c); fflush(stdout);
    int res; scanf("%d", &res);
    M.insert(make_pair(seq, res));
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        M.clear();
        scanf("%d", &n);
        int good, bad;
        int mem = Ask(1, 2, 3);
        int i = 1;
        while (Ask(3 * i + 1, 3 * i + 2, 3 * i + 3) == mem) i++;
        int lst = 3 * i - 2;
        while (Ask(lst, lst + 1, lst + 2) == mem) lst++;
        int lef = lst - 1;
        int rig = lef + 3;
        res[lef] = mem; res[rig] = !mem;
        res[lef + 1] = Ask(lef, rig, lef + 1);
        res[lef + 2] = !res[lef + 1];
        for (int j = rig + 1; j <= n; j++)
            res[j] = Ask(lef, rig, j);
        for (int j = 3 * i - 2; j < lef; j++)
            res[j] = Ask(lef, rig, j);
        i -= 2;
        while (i >= 0) {
            int a = 3 * i + 1, b = 3 * i + 2, c = 3 * i + 3;
            int got = Ask(rig, a, b);
            if (got == mem) {
                res[a] = res[b] = mem;
                res[c] = Ask(lef, rig, c);
            } else {
                res[a] = Ask(lef, rig, a);
                res[b] = !res[a];
                res[c] = mem;
            }
            i--;
        }
        vector <int> ans;
        for (int i = 1; i <= n; i++) if (res[i] == 0)
            ans.push_back(i);
        printf("! %d", int(ans.size()));
        for (int i = 0; i < ans.size(); i++)
            printf(" %d", ans[i]);
        printf("\n"); fflush(stdout);
    }
    return 0;
}