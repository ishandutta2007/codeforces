#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 600015;
const int nil = 300005;

int q;
int X[Maxn], Y[Maxn];
bool add[Maxn];
int tim[Maxn];
map <ii, int> M;
int par[Maxn], siz[Maxn];
int myR[Maxn], myC[Maxn];
ll cur;
vector <ii> seq;
ll res[Maxn];

int getPar(int x) { return par[x] == x? x: getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    seq.push_back(ii(a, b));
    cur -= ll(myR[a]) * myC[a];
    cur -= ll(myR[b]) * myC[b];
    siz[a] += siz[b]; par[b] = a;
    myR[a] += myR[b]; myC[a] += myC[b];
    cur += ll(myR[a]) * myC[a];
}

void Undo(int sz)
{
    while (seq.size() > sz) {
        ii ab = seq.back(); seq.pop_back();
        int a = ab.first, b = ab.second;
        cur -= ll(myR[a]) * myC[a];
        siz[a] -= siz[b]; par[b] = b;
        myR[a] -= myR[b]; myC[a] -= myC[b];
        cur += ll(myR[a]) * myC[a];
        cur += ll(myR[b]) * myC[b];
    }
}

void Solve(int l, int r)
{
    if (l == r) {
        int sz = seq.size();
        if (add[l]) unionSet(X[l], Y[l] + nil);
        res[l] = cur;
        if (add[l]) Undo(sz);
    } else {
        int m = l + r >> 1, sz = seq.size();
        for (int i = m + 1; i <= r; i++)
            if (tim[i] <= l) unionSet(X[i], Y[i] + nil);
        Solve(l, m);
        Undo(sz);
        for (int i = l; i <= m; i++)
            if (tim[i] > r) unionSet(X[i], Y[i] + nil);
        Solve(m + 1, r);
        Undo(sz);
    }
}

int main()
{
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        map <ii, int>::iterator it = M.find(ii(X[i], Y[i]));
        if (it == M.end()) {
            add[i] = true;
            M.insert(make_pair(ii(X[i], Y[i]), i));
        } else {
            tim[it->second] = i;
            tim[i] = it->second;
            M.erase(it);
        }
    }
    for (int i = 0; i < Maxn; i++) {
        par[i] = i; siz[i] = 1;
        if (i < nil) myR[i] = 1;
        else myC[i] = 1;
    }
    int sz = q;
    for (map <ii, int>::iterator it = M.begin(); it != M.end(); it++) {
        tim[q] = it->second;
        tim[it->second] = q;
        X[q] = X[it->second], Y[q] = Y[it->second];
        q++;
    }
    Solve(0, q - 1);
    for (int i = 0; i < sz; i++)
        printf("%I64d%c", res[i], i + 1 < sz? ' ': '\n');
    return 0;
}