#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;
const int Maxs = 200005;

int T;
int n, m;
int a[Maxn];
vector <int> un;
int cnt[Maxn];
ii st[Maxm];
vector <int> G[Maxn];
ll gsum[Maxn];
char res[Maxs];
int rlen;

ii Union(const ii &a, const ii &b)
{
    int tk = min(a.second, b.first);
    return ii(a.first + b.first - tk, a.second + b.second - tk);
}

void Clear(int v, int l, int r)
{
    if (l == r) st[v] = ii(cnt[l], 0);
    else {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int x, int val)
{
    if (l == r) {
        cnt[l] -= val;
        st[v] = cnt[l] >= 0? ii(cnt[l], 0): ii(0, -cnt[l]);
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x, val);
        else Update(2 * v + 1, m + 1, r, x, val);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int getInd(ll sum, int k)
{
    int nd = (sum - 1) / k + 1;
    return lower_bound(un.begin(), un.end(), nd) - un.begin();
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        un.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            un.push_back(a[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        fill(cnt, cnt + int(un.size()) + 1, 0);
        for (int i = 0; i < n; i++) {
            int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
            cnt[ind]++;
        }
        Clear(1, 0, int(un.size()));
        for (int i = 0; i < m; i++) {
            gsum[i] = 0;
            int k; scanf("%d", &k);
            G[i].resize(k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &G[i][j]);
                gsum[i] += G[i][j];
            }
            Update(1, 0, int(un.size()), getInd(gsum[i], k), 1);
        }
        rlen = 0;
        for (int i = 0; i < m; i++) {
            int old = getInd(gsum[i], G[i].size());
            Update(1, 0, int(un.size()), old, -1);
            for (int j = 0; j < G[i].size(); j++) {
                int nw = getInd(gsum[i] - G[i][j], int(G[i].size()) - 1);
                Update(1, 0, int(un.size()), nw, 1);
                res[rlen++] = '0' + int(st[1].second == 0);
                Update(1, 0, int(un.size()), nw, -1);
            }
            Update(1, 0, int(un.size()), old, 1);
        }
        res[rlen] = '\0';
        printf("%s\n", res);
    }
    return 0;
}