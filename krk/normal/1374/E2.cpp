#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int n, m, k;
int T[Maxn];
vector <ii> A, B, C;
ll res = Inf;
int bres;
set <ii> S;
set <ii> S1, S2;
ll inSet;
vector <ii> sav;

bool Enough(int nd) { return S1.size() + S2.size() >= nd; }

void Fix(int nd)
{
    if (!Enough(nd)) return;
    while (S1.size() < nd) {
        auto it = S2.begin();
        S1.insert(*it);
        inSet += it->first;
        S2.erase(it);
    }
    while (S1.size() > nd) {
        auto it = S1.end(); it--;
        S2.insert(*it);
        inSet -= it->first;
        S1.erase(it);
    }
}

void Add(const ii &p)
{
    if (S1.empty()) { S2.insert(p); return; }
    auto it = S1.end(); it--;
    if (p <= *it) { S1.insert(p); inSet += p.first; }
    else S2.insert(p);
}

void Remove(const ii &p)
{
    auto it = S1.find(p);
    if (it != S1.end()) {
        inSet -= it->first;
        S1.erase(it);
    } else {
        it = S2.find(p);
        S2.erase(it);
    }
}

bool Less(const ii &a, const ii &b)
{
    return T[a.first] < T[b.first];
}

void Prepare(vector <ii> &V)
{
    sort(V.begin() + 1, V.end(), Less);
    for (int i = 1; i < V.size(); i++)
        V[i].second = V[i - 1].second + T[V[i].first];
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    A.push_back(ii(0, 0));
    B.push_back(ii(0, 0));
    C.push_back(ii(0, 0));
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d %d", &T[i], &a, &b);
        if (a && !b) A.push_back(ii(i, 0));
        if (b && !a) B.push_back(ii(i, 0));
        if (a && b) C.push_back(ii(i, 0));
        if (!a && !b) { Add(ii(T[i], i)); sav.push_back(ii(T[i], i)); }
    }
    Prepare(A);
    Prepare(B);
    Prepare(C);
    for (int i = 1; i < A.size(); i++)
        Add(ii(T[A[i].first], A[i].first));
    for (int i = 1; i < B.size(); i++)
        Add(ii(T[B[i].first], B[i].first));
    int mx = min(int(C.size()) - 1, m);
    int pntA = 0, pntB = 0;
    ll cur = 0;
    for (int i = 1; i <= mx; i++)
        cur += T[C[i].first];
    for (int i = mx + 1; i < C.size(); i++)
        Add(ii(T[C[i].first], C[i].first));
    int rem = m - mx;
    while (mx >= 0) {
        while (pntA + 1 < A.size() && pntA + mx < k) {
            rem--;
            pntA++;
            Remove(ii(T[A[pntA].first], A[pntA].first));
            cur += T[A[pntA].first];
        }
        while (pntB + 1 < B.size() && pntB + mx < k) {
            rem--;
            pntB++;
            Remove(ii(T[B[pntB].first], B[pntB].first));
            cur += T[B[pntB].first];
        }
        if (pntA + mx >= k && pntB + mx >= k && rem >= 0 && Enough(rem)) {
            Fix(rem);
            if (cur + inSet < res) {
                res = cur + inSet;
                bres = mx;
            }
        }
        if (mx == 0) break;
        rem++;
        Add(ii(T[C[mx].first], C[mx].first));
        cur -= T[C[mx].first];
        mx--;
    }
    if (res >= Inf) { printf("-1\n"); return 0; }
    printf("%I64d\n", res);
    S1.clear(); S2.clear();
    inSet = 0;
    mx = bres;
    vector <int> seq;
    for (int i = 1; i <= mx; i++)
        seq.push_back(C[i].first);
    for (int i = mx + 1; i < C.size(); i++)
        Add(ii(T[C[i].first], C[i].first));
    pntA = 0, pntB = 0;
    while (pntA + 1 < A.size() && pntA + mx < k)
        seq.push_back(A[++pntA].first);
    for (int i = pntA + 1; i < A.size(); i++)
        Add(ii(T[A[i].first], A[i].first));
    while (pntB + 1 < B.size() && pntB + mx < k)
        seq.push_back(B[++pntB].first);
    for (int i = pntB + 1; i < B.size(); i++)
        Add(ii(T[B[i].first], B[i].first));
    for (int i = 0; i < sav.size(); i++)
        Add(sav[i]);
    Fix(m - int(seq.size()));
    for (auto it: S1)
        seq.push_back(it.second);
    for (int i = 0; i < seq.size(); i++)
        printf("%d%c", seq[i] + 1, i + 1 < seq.size()? ' ': '\n');
    return 0;
}