#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 1005;
const int Maxm = 30000;

int n;
int A[Maxn], B[Maxn];
int C[Maxm], D[Maxm];
int M;
set <iii> neigh[Maxn];
vector <int> best[Maxn];
vector <ii> res;

int getSide(int a, int b, int c)
{
    if (a <= b) return a < c && c < b? 1: 2;
    else return c > a || c < b? 1: 2;
}

bool Intersect(int ind, int i, iii &res)
{
    if (C[ind] == A[i] || C[ind] == B[i] || D[ind] == A[i] || D[ind] == B[i])
        return false;
    int s1 = getSide(A[i], B[i], C[ind]);
    int s2 = getSide(A[i], B[i], D[ind]);
    if (s1 == s2) return false;
    int c = C[ind], d = D[ind];
    if (s1 == 2) swap(c, d);
    res.first = ii((c - A[i] + n) % n, (A[i] - d + n) % n);
    res.second = ind;
    return true;
}

void addAll(int ind)
{
    iii tmp;
    for (int i = 0; i < n - 3; i++)
        if (Intersect(ind, i, tmp)) {
            neigh[i].insert(tmp);
            best[neigh[i].size()].push_back(i);
        }
}

void remAll(int ind)
{
    iii tmp;
    for (int i = 0; i < n - 3; i++)
        if (Intersect(ind, i, tmp)) {
            neigh[i].erase(tmp);
            best[neigh[i].size()].push_back(i);
        }
}

void popOne(int ind)
{
    auto it = neigh[ind].begin();
    int rem = it->second;
    ii add = ii(-1, -1);
    it++;
    if (it != neigh[ind].end()) {
        int rem2 = it->second;
        if (C[rem2] == C[rem] || C[rem2] == D[rem])
            add = ii(A[ind], D[rem2]);
        else add = ii(A[ind], C[rem2]);
    }
    res.push_back(ii(C[rem], D[rem]));
    remAll(rem);
    if (add.first != -1) {
        C[M] = add.first;
        D[M] = add.second;
        M++;
        addAll(M - 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 3; i++)
        scanf("%d %d", &C[i], &D[i]);
    for (int i = 0; i < n - 3; i++)
        scanf("%d %d", &A[i], &B[i]);
    M = n - 3;
    for (int i = 0; i < M; i++)
        addAll(i);
    while (true) {
        bool had = false;
        for (int i = 1; i < Maxn && !had; i++) {
            while (!best[i].empty() && !had) {
                int v = best[i].back(); best[i].pop_back();
                if (neigh[v].size() != i) continue;
                popOne(v);
                had = true;
            }
        }
        if (!had) break;
    }
    assert(res.size() <= 20000);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}