#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
const int Maxm = 2097152;
const int Maxb = 20;

int mx[1 << Maxb];
int n;
int c[Maxn];
int q;
int qa[Maxn], qb[Maxn];
vector <int> quer[Maxn];
int my[Maxb], lvl[Maxb];
int res[Maxn];

void realInsert(int ind, int val)
{
    while (val)
        if (my[mx[val]]) val ^= my[mx[val]];
        else { my[mx[val]] = val; lvl[mx[val]] = ind; break; }
}

void Insert(int ind, int val)
{
    bool rep = false;
    while (val)
        if (my[mx[val]]) { rep = true; break; }
        else { my[mx[val]] = val; lvl[mx[val]] = ind; break; }
    if (rep) {
        vector <int> seq;
        seq.push_back(ind);
        for (int i = 0; i < Maxb; i++) if (my[i])
            seq.push_back(lvl[i]);
        sort(seq.rbegin(), seq.rend());
        fill(my, my + Maxb, 0);
        for (int i = 0; i < seq.size(); i++)
            realInsert(seq[i], c[seq[i]]);
    }
}

int getMax(int l)
{
    int cur = 0;
    for (int i = Maxb - 1; i >= 0; i--) if (!(cur & 1 << i) && lvl[i] >= l)
        cur ^= my[i];
    return cur;
}

int main()
{
    mx[0] = -1;
    for (int i = 1; i < 1 << Maxb; i++) {
        int my = (i & -i);
        if (my == i) mx[i] = __builtin_popcount(my - 1);
        else mx[i] = mx[i ^ my];
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        quer[qb[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        Insert(i, c[i]);
        for (int j = 0; j < quer[i].size(); j++) {
            int ind = quer[i][j];
            res[ind] = getMax(qa[ind]);
        }
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}