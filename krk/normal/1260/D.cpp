#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxs = 1048576;

int st[Maxs];
bool black[Maxs];
int cnt[Maxs], len[Maxs];
int m, n, k, t;
int freq[Maxn];
vector <ii> my[Maxn];

void Down(int v)
{
    if (black[v])
        black[2 * v] = black[2 * v + 1] = true;
}

int Get(int v) { return black[v]? len[v]: cnt[v]; }

void Union(int v)
{
    cnt[v] = Get(2 * v) + Get(2 * v + 1);
}

void Create(int v, int l, int r)
{
    len[v] = r - l + 1;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void Add(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) black[v] = true;
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Add(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b);
        Union(v);
    }
}

int Count(int x)
{
    int res = 0;
    for (int i = x; i < Maxn; i++)
        res += freq[i];
    return res;
}

int main()
{
    scanf("%d %d %d %d", &m, &n, &k, &t);
    Create(1, 1, n);
    for (int i = 0; i < m; i++) {
        int a; scanf("%d", &a);
        freq[a]++;
    }
    for (int i = 0; i < k; i++) {
        int l, r, d; scanf("%d %d %d", &l, &r, &d);
        my[d].push_back(ii(l, r));
    }
    for (int i = Maxn - 1; i >= 0; i--) {
        for (int j = 0; j < my[i].size(); j++)
            Add(1, 1, n, my[i][j].first, my[i][j].second);
        if (n + 1 + 2 * Get(1) > t) { printf("%d\n", Count(i)); return 0; }
    }
    printf("%d\n", Count(0));
    return 0;
}