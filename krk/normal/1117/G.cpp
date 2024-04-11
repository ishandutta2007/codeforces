#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> llll;

const int Maxn = 1000005;
const int Maxm = 4194304;

int n, q;
int P[Maxn];
vector <int> S;
int lef[Maxn], rig[Maxn];
ll A[2][Maxm];
int B[2][Maxm], C[2][Maxm];
int qa[Maxn], qb[Maxn];
ll qres[Maxn];
vector <int> upd[Maxn], quer[Maxn];

void Add(int s, int v, int l, int r, int a, int b, ll myA, ll myB, ll myC)
{
    if (l == a && r == b) { A[s][v] += myA; B[s][v] += myB; C[s][v] += myC; }
    else {
        int m = l + r >> 1;
        if (b <= m) Add(s, 2 * v, l, m, a, b, myA, myB, myC);
        else if (m + 1 <= a) Add(s, 2 * v + 1, m + 1, r, a, b, myA, myB, myC);
        else {
            Add(s, 2 * v, l, m, a, m, myA, myB, myC);
            Add(s, 2 * v + 1, m + 1, r, m + 1, b, myA + myB * (m + 1 - a), myB, myC);
        }
    }
}

llll Get(int s, int v, int l, int r, int x)
{
    llll res = llll(A[s][v] + ll(B[s][v]) * (x - l), C[s][v]);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) {
            llll g = Get(s, 2 * v, l, m, x);
            res.first += g.first;
            res.second += g.second;
        } else {
            llll g = Get(s, 2 * v + 1, m + 1, r, x);
            res.first += g.first;
            res.second += g.second;
        }
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
        while (!S.empty() && P[S.back()] < P[i]) {
            rig[S.back()] = i - 1; S.pop_back();
        }
        if (S.empty()) lef[i] = 1;
        else lef[i] = S.back() + 1;
        S.push_back(i);
    }
    while (!S.empty()) {
        rig[S.back()] = n; S.pop_back();
    }
    for (int i = 1; i <= n; i++) {
        Add(0, 1, 1, n, i, rig[i], i - lef[i] + 1, 1, 1);
        if (rig[i] < n)
            Add(0, 1, 1, n, rig[i] + 1, n, rig[i] - lef[i] + 1, 0, 1);
        upd[lef[i]].push_back(i);
        upd[i + 1].push_back(i);
    }
    for (int i = 1; i <= q; i++)
        scanf("%d", &qa[i]);
    for (int i = 1; i <= q; i++) {
        scanf("%d", &qb[i]);
        quer[qa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < upd[i].size(); j++) {
            int ind = upd[i][j];
            if (i == lef[ind]) {
                Add(0, 1, 1, n, ind, rig[ind], -(ind - lef[ind] + 1), -1, -1);
                if (rig[ind] < n)
                    Add(0, 1, 1, n, rig[ind] + 1, n, -(rig[ind] - lef[ind] + 1), 0, -1);
                Add(1, 1, 1, n, ind, rig[ind], ind + 1, 1, 1);
                if (rig[ind] < n)
                    Add(1, 1, 1, n, rig[ind] + 1, n, rig[ind] + 1, 0, 1);
            } else {
                Add(1, 1, 1, n, ind, rig[ind], -(ind + 1), -1, -1);
                if (rig[ind] < n)
                    Add(1, 1, 1, n, rig[ind] + 1, n, -(rig[ind] + 1), 0, -1);
            }
        }
        for (int j = 0; j < quer[i].size(); j++) {
            int ind = quer[i][j];
            ll A = Get(0, 1, 1, n, qb[ind]).first;
            llll got = Get(1, 1, 1, n, qb[ind]);
            qres[ind] = A + ll(got.first) - ll(i) * got.second;
        }
    }
    for (int i = 1; i <= q; i++)
        printf("%I64d%c", qres[i], i + 1 <= q? ' ': '\n');
    return 0;
}