#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int T;
int n;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn];
int r, dist;

ii Ask(bool mor, int num, int forb)
{
    vector <int> seq;
    for (int i = 1; i <= n; i++) if (forb != i)
        if (mor && L[i] > num || !mor && L[i] == num)
            seq.push_back(i);
    assert(!seq.empty());
    printf("? %d", int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf(" %d", seq[i]);
    printf("\n"); fflush(stdout);
    int res1, res2; scanf("%d %d", &res1, &res2);
    return ii(res1, res2);
}

void Traverse(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        L[u] = L[v] + 1; P[u] = v;
        Traverse(u, v);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            L[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        ii got = Ask(false, 0, -1);
        r = got.first, dist = got.second;
        Traverse(r, 0);
        int mx = 0;
        for (int i = 1; i <= n; i++)
            mx = max(mx, L[i]);
        int lef = dist / 2, rig = min(dist, mx);
        int A = -1;
        while (lef < rig) {
            int mid = (lef + rig - 1) >> 1;
            ii got = Ask(true, mid, -1);
            if (got.second == dist) {
                A = got.first;
                lef = mid + 1;
            } else rig = mid;
        }
        if (A == -1) A = Ask(false, lef, -1).first;
        int nlvl = dist - L[A];
        int av = A;
        while (L[av] > nlvl) av = P[av];
        int B = av == r? r: Ask(false, nlvl, av).first;
        printf("! %d %d\n", A, B); fflush(stdout);
        string dum; cin >> dum;
    }
    return 0;
}