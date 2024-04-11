#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
const int Maxm = 1048576;

struct node {
    int siz;
    int cnt;
    int sum;
};

int T;
int n;
int L[Maxn], R[Maxn], C[Maxn];
vector <int> my[Maxn];
node st[Maxm];
int res[Maxn];

int Get(const node &a) { return a.cnt? a.siz: a.sum; }

void Create(int v, int l, int r)
{
    st[v].siz = r - l + 1;
    st[v].cnt = 0;
    st[v].sum = 0;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void Update(int v, int l, int r, int a, int b, int delt)
{
    if (l == a && r == b) st[v].cnt += delt;
    else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        st[v].sum = Get(st[2 * v]) + Get(st[2 * v + 1]);
    }
}

bool Get(int v, int l, int r, int a, int b)
{
    if (st[v].cnt) return true;
    else if (l == a && r == b) return st[v].sum > 0;
    else {
        int m = l + r >> 1;
        if (a <= m && Get(2 * v, l, m, a, min(m, b)))
            return true;
        if (m + 1 <= b && Get(2 * v + 1, m + 1, r, max(m + 1, a), b))
            return true;
        return false;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> un;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &L[i], &R[i], &C[i]);
            my[i].clear();
            un.push_back(L[i]);
            un.push_back(R[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        Create(1, 0, int(un.size()) - 1);
        for (int i = 1; i <= n; i++) {
            my[C[i]].push_back(i);
            L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
            R[i] = lower_bound(un.begin(), un.end(), R[i]) - un.begin();
            Update(1, 0, int(un.size()) - 1, L[i], R[i], 1);
        }
        for (int c = 1; c <= n; c++) {
            for (int z = 0; z < my[c].size(); z++) {
                int i = my[c][z];
                Update(1, 0, int(un.size()) - 1, L[i], R[i], -1);
            }
            for (int z = 0; z < my[c].size(); z++) {
                int i = my[c][z];
                int lef = 0, rig = 1000000007;
                while (lef <= rig) {
                    int mid = lef + rig >> 1;
                    int lw = lower_bound(un.begin(), un.end(), un[L[i]] - mid) - un.begin();
                    int hg = upper_bound(un.begin(), un.end(), un[R[i]] + mid) - un.begin() - 1;
                    if (Get(1, 0, int(un.size()) - 1, lw, hg)) rig = mid - 1;
                    else lef = mid + 1;
                }
                res[i] = lef;
            }
            for (int z = 0; z < my[c].size(); z++) {
                int i = my[c][z];
                Update(1, 0, int(un.size()) - 1, L[i], R[i], 1);
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}