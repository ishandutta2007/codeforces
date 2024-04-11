#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 250005;
const int Maxm = 1048576;

int x, y, p, r, n;
int xi[Maxn], yi[Maxn], mi[Maxn], pi[Maxn], ri[Maxn];
bool taken[Maxn];
vector <ll> un;
vector <vector <int> > inpl;
vector <int> Q;
vector <int> st[Maxm];

ll Dist(int ax, int ay) { return ll(ax) * ll(ax) + ll(ay) * ll(ay); }

bool Less(const int &a, const int &b) { return mi[a] > mi[b]; }

void Create(int v, int l, int r)
{
    if (l == r) st[v] = inpl[l];
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
        int i = 0, j = 0;
        while (i < st[2 * v].size() || j < st[2 * v + 1].size())
            if (i < st[2 * v].size() && (j == st[2 * v + 1].size() || mi[st[2 * v][i]] >= mi[st[2 * v + 1][j]]))
                st[v].push_back(st[2 * v][i++]);
            else st[v].push_back(st[2 * v + 1][j++]);
    }
}

void Get(int v, int l, int r, int a, int b, int p)
{
    if (l == a && r == b)
        while (!st[v].empty() && mi[st[v].back()] <= p) {
            if (!taken[st[v].back()]) { taken[st[v].back()] = true; Q.push_back(st[v].back()); }
            st[v].pop_back();
        }
    else {
        int m = l + r >> 1;
        if (a <= m) Get(2 * v, l, m, a, min(m, b), p);
        if (m + 1 <= b) Get(2 * v + 1, m + 1, r, max(m + 1, a), b, p);
    }
}

void Get(ll r, int p)
{
    int ind = upper_bound(un.begin(), un.end(), r) - un.begin() - 1;
    if (ind < 0) return;
    Get(1, 0, un.size() - 1, 0, ind, p);
}

int main()
{
    scanf("%d %d %d %d %d", &x, &y, &p, &r, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d", &xi[i], &yi[i], &mi[i], &pi[i], &ri[i]);
        un.push_back(Dist(x - xi[i], y - yi[i]));
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    inpl.resize(un.size());
    for (int i = 0; i < n; i++) {
        ll len = Dist(x - xi[i], y - yi[i]);
        int ind = lower_bound(un.begin(), un.end(), len) - un.begin();
        inpl[ind].push_back(i);
    }
    for (int i = 0; i < un.size(); i++)
        sort(inpl[i].begin(), inpl[i].end(), Less);
    Create(1, 0, un.size() - 1);
    Get(ll(r) * ll(r), p);
    for (int i = 0; i < Q.size(); i++)
        Get(ll(ri[Q[i]]) * ll(ri[Q[i]]), pi[Q[i]]);
    printf("%d\n", Q.size());
    return 0;
}