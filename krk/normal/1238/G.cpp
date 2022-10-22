#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 500005;
const int Maxm = 2097152;

int q;
int n, m, c, c0;
int T[Maxn], A[Maxn], B[Maxn];
vector <int> un;
int BIT[Maxn];
int st[Maxm];
int flag[Maxm];
vector <ii> my[Maxn];

void Update(int ind, int val)
{
    ind++;
    for (int i = ind; i <= un.size(); i += i & -i)
        BIT[i] += val;
}

int Get(int ind)
{
    ind++;
    int res = 0;
    for (int i = ind; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void downOn(int v, int f)
{
    st[v] += f;
    flag[v] += f;
}

void Down(int v)
{
    if (flag[v]) {
        downOn(2 * v, flag[v]);
        downOn(2 * v + 1, flag[v]);
        flag[v] = 0;
    }
}

void Create(int v, int l, int r)
{
    flag[v] = 0;
    if (l == r) st[v] = c0 - un[l];
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = max(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        st[v] = max(st[2 * v], st[2 * v + 1]);
    }
}

int Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        Down(v);
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return max(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d %d", &n, &m, &c, &c0);
        un.clear();
        un.push_back(0);
        un.push_back(m);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &T[i], &A[i], &B[i]);
            un.push_back(T[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        for (int i = 0; i <= un.size() + 1; i++) {
            my[i].clear();
            BIT[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int ind = lower_bound(un.begin(), un.end(), T[i]) - un.begin();
            my[ind].push_back(ii(A[i], B[i]));
        }
        Create(1, 0, int(un.size()) - 1);
        Update(0, c0);
        priority_queue <iii> Q;
        int pnt = 0, cur = c0;
        ll res = 0;
        while (cur < m) {
            while (un[pnt] <= cur) {
                for (int i = 0; i < my[pnt].size(); i++)
                    Q.push(iii(-my[pnt][i].second, ii(my[pnt][i].first, pnt)));
                pnt++;
            }
            if (Q.empty()) break;
            iii p = Q.top(); Q.pop();
            int nd = un[pnt] - cur;
            int lvl = max(Get(1, 0, int(un.size()) - 1, p.second.second, int(un.size()) - 1),
                          Get(p.second.second) - un[p.second.second]);
            p.second.first = min(p.second.first, c - lvl);
            int tk = min(nd, p.second.first);
            p.second.first -= tk;
            Update(1, 0, int(un.size()) - 1, p.second.second, int(un.size()) - 1, tk);
            Update(p.second.second, tk);
            cur += tk;
            res += ll(tk) * ll(-p.first);
            if (p.second.first > 0)
                Q.push(p);
        }
        if (cur < m) printf("-1\n");
        else printf("%I64d\n", res);
    }
    return 0;
}