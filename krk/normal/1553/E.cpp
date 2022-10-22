#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n, m;
int a[Maxn];
int vote[Maxn];
int p[Maxn], inp[Maxn];
int nxt[Maxn];

bool Solve(int k)
{
    int pnt = 0;
    for (int i = k; i > 0; i--)
        p[pnt++] = n - i;
    for (int i = 0; i < n - k; i++)
        p[pnt++] = i;
    for (int i = 0; i < n; i++)
        inp[p[i]] = i;
    for (int i = 0; i < n; i++)
        nxt[i] = inp[a[i]];
    int res = 0;
    for (int i = 0; i < n; i++) if (nxt[i] != -1) {
        int len = 0;
        int cur = i;
        while (nxt[cur] != -1) {
            int ncur = nxt[cur];
            nxt[cur] = -1;
            len++;
            cur = ncur;
        }
        res += len - 1;
    }
    return res <= m;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(vote, vote + n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]); a[i]--;
            vote[(i - a[i] + n) % n]++;
        }
        vector <int> res;
        for (int i = 0; i < n; i++) if (vote[i] >= n / 3)
            if (Solve(i)) res.push_back(i);
        printf("%d", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf(" %d", res[i]);
        printf("\n");
    }
    return 0;
}