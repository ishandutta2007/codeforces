#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

int T;
int n;
int C[Maxn], L[Maxn], R[Maxn];
bool tk[Maxn];
vector <int> un;
vector <int> all[2][Maxm], has[2][Maxm];
vector <int> nxt;

void Clear(int t, int v, int l, int r)
{
    all[t][v].clear();
    has[t][v].clear();
    if (l < r) {
        int m = l + r >> 1;
        Clear(t, 2 * v, l, m);
        Clear(t, 2 * v + 1, m + 1, r);
    }
}

void Add(int t, int v, int l, int r, int a, int b, int val)
{
    has[t][v].push_back(val);
    if (l == a && r == b) all[t][v].push_back(val);
    else {
        int m = l + r >> 1;
        if (a <= m) Add(t, 2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Add(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
    }
}


void Process(vector <int> &V)
{
    while (!V.empty()) {
        int u = V.back(); V.pop_back();
        if (!tk[u]) {
            tk[u] = true;
            nxt.push_back(u);
        }
    }
}

void Get(int t, int v, int l, int r, int a, int b)
{
    Process(all[t][v]);
    if (l == a && r == b)
        Process(has[t][v]);
    else {
        int m = l + r >> 1;
        if (a <= m) Get(t, 2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Get(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        un.clear();
        for (int i = 1; i <= n; i++) {
            tk[i] = false;
            scanf("%d %d %d", &C[i], &L[i], &R[i]);
            un.push_back(L[i]);
            un.push_back(R[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        for (int t = 0; t < 2; t++)
            Clear(t, 1, 0, int(un.size()) - 1);
        for (int i = 1; i <= n; i++) {
            L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
            R[i] = lower_bound(un.begin(), un.end(), R[i]) - un.begin();
            Add(C[i], 1, 0, int(un.size()) - 1, L[i], R[i], i);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) if (!tk[i]) {
            res++;
            vector <int> seq = {i};
            int t = C[i];
            while (!seq.empty()) {
                nxt.clear();
                for (int i = 0; i < seq.size(); i++)
                    Get(!t, 1, 0, int(un.size()) - 1, L[seq[i]], R[seq[i]]);
                t = !t;
                seq = nxt;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}