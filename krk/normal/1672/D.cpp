#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int b[Maxn];
vector <int> inds[Maxn];
int cnt[Maxn];

bool Solve()
{
    int lst = 0;
    for (int i = 1, j; i <= n; i = j) {
        j = i;
        while (j <= n && b[i] == b[j]) j++;
        cnt[b[i]] += j - i;
        int ind = upper_bound(inds[b[i]].begin(), inds[b[i]].end(), lst) - inds[b[i]].begin();
        ind = max(ind, cnt[b[i]] - 1);
        if (ind >= inds[b[i]].size()) return false;
        lst = inds[b[i]][ind];
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            inds[i].clear();
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            inds[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}