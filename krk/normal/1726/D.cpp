#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n, m;
int par[Maxn], siz[Maxn];
int A[Maxn], B[Maxn];
vector <ii> neigh[Maxn];
ii P[Maxn];
int L[Maxn];
char res[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = par[a];
    return true;
}

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (P[v].first == u.first) continue;
        P[u.first] = ii(v, u.second);
        L[u.first] = L[v] + 1;
        Traverse(u.first);
    }
}

void Update(vector <int> &seq)
{
    if (seq.size() < 3) return;
    map <int, int> M;
    for (int i = 0; i < seq.size(); i++) {
        M[A[seq[i]]]++;
        M[B[seq[i]]]++;
    }
    for (auto p: M)
        if (p.second != 2) return;
    int ind = seq.back();
    seq.back() = L[A[ind]] >= L[B[ind]]? P[A[ind]].second: P[B[ind]].second;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            siz[i] = 1;
            neigh[i].clear();
        }
        vector <int> seq;
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            A[i] = a; B[i] = b;
            res[i] = '0';
            if (unionSet(a, b)) {
                neigh[a].push_back(ii(b, i));
                neigh[b].push_back(ii(a, i));
            } else seq.push_back(i);
        }
        Traverse(1);
        Update(seq);
        for (int i = 0; i < seq.size(); i++)
            res[seq[i]] = '1';
        res[m] = '\0';
        printf("%s\n", res);
    }
    return 0;
}