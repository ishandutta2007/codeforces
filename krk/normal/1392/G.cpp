#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int Maxm = 1 << 20;
const int Maxk = 21;

int n, m, k;
int P[Maxn], iP[Maxn];
int st, en;
int stmult[Maxn], enmult[Maxn];
vector <int> V[Maxm];
int was[Maxm];
int res = 0;
int bi, bj;

void getInverse(int P[], int iP[])
{
    for (int i = 0; i < k; i++)
        iP[P[i]] = i;
}

int Multiply(int mask, int P[])
{
    int nmask = 0;
    for (int i = 0; i < k; i++) {
        int ind = P[i];
        if (bool(mask & 1 << ind))
            nmask |= 1 << i;
    }
    return nmask;
}

int readMask()
{
    string s; cin >> s;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1') res |= 1 << i;
    return res;
}

void Solve(int ind, int mask, int ex)
{
    if (ex <= was[mask] || ex <= res) return;
    was[mask] = ex;
    while (!V[mask].empty() && ind - V[mask].back() < m)
        V[mask].pop_back();
    if (!V[mask].empty()) {
        res = ex;
        bi = V[mask].back();
        bj = ind;
    }
    for (int i = 0; i < k; i++)
        Solve(ind, (mask ^ (1 << i)), ex - 1);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++)
        P[i] = iP[i] = i;
    st = readMask();
    en = readMask();
    bi = 0, bj = n;
    stmult[0] = st;
    enmult[0] = en;
    V[stmult[0]].push_back(0);
    for (int i = 1; i <= n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        a--; b--;
        swap(P[a], P[b]);
        getInverse(P, iP);
        stmult[i] = Multiply(st, iP);
        enmult[i] = Multiply(en, iP);
        V[stmult[i]].push_back(i);
    }
    for (int i = n; i > 0; i--)
        Solve(i, enmult[i], k);
    printf("%d\n", res);
    printf("%d %d\n", bi + 1, bj);
    return 0;
}