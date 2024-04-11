#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
vector <int> seq;
int cnt[Maxn];

bool Solve(int x)
{
    fill(cnt, cnt + n + 1, 0);
    for (int i = 0; i < seq.size(); i++)
        cnt[seq[i]]++;
    int t = 0, rem = 0;
    for (int i = n; i > 0; i--)
        for (int j = 0; j < cnt[i]; j++) {
            t++;
            if (t > x) return false;
            int tk = x + 1 - t;
            if (tk >= i) continue;
            rem += i - tk;
        }
    return t + rem <= x;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        seq.clear();
        for (int i = 2; i <= n; i++) {
            int v; scanf("%d", &v);
            neigh[v].push_back(i);
        }
        for (int i = 1; i <= n; i++) if (!neigh[i].empty())
            seq.push_back(neigh[i].size());
        seq.push_back(1);
        sort(seq.rbegin(), seq.rend());
        int lef = 1, rig = n;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Solve(mid)) rig = mid - 1;
            else lef = mid + 1;
        }
        printf("%d\n", lef);
    }
    return 0;
}