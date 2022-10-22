#include <bits/stdc++.h>
using namespace std;

const int Maxp = 11000000;
const int Maxb = 30;
const int Maxn = 300005;

struct pos {
    int ch[2];
    int ind;
    pos() { ch[0] = ch[1] = 0; ind = 0; }
};

pos tr[Maxp];
int tlen;
int n, k;
int a[Maxn];
vector <int> V;
vector <int> res;

void Add(int ind, int mask, int lvl, int sav)
{
    if (lvl < 0) tr[ind].ind = sav;
    else {
        int b = bool(mask & 1 << lvl);
        if (!tr[ind].ch[b]) tr[ind].ch[b] = tlen++;
        Add(tr[ind].ch[b], mask, lvl - 1, sav);
    }
}

int Get(int ind, int mask, int lvl)
{
    if (lvl < 0) return tr[ind].ind;
    else {
        int b = !bool(mask & 1 << lvl);
        if (tr[ind].ch[b]) return Get(tr[ind].ch[b], mask, lvl - 1);
        else return Get(tr[ind].ch[!b], mask, lvl - 1);
    }
}

void Solve(const vector <int> &V, int b)
{
    if (V.empty()) return;
    vector <int> ones, zers;
    for (int i = 0; i < V.size(); i++)
        if (a[V[i]] & 1 << b) ones.push_back(V[i]);
        else zers.push_back(V[i]);
    if (1 << b > k) {
        Solve(ones, b - 1);
        Solve(zers, b - 1);
    } else {
        if (!ones.empty() && !zers.empty()) {
            int cur = tlen++;
            for (int i = 0; i < zers.size(); i++)
                Add(cur, a[zers[i]], b, zers[i]);
            for (int i = 0; i < ones.size(); i++) {
                int got = Get(cur, a[ones[i]], b);
                if ((a[got] ^ a[ones[i]]) >= k) {
                    res.push_back(got);
                    res.push_back(ones[i]);
                    return;
                }
            }
        }
        res.push_back(V[0]);
    }
}

void Print(const vector <int> &V)
{
    if (V.size() < 2) printf("-1\n");
    else {
        printf("%d\n", int(V.size()));
        for (int i = 0; i < V.size(); i++)
            printf("%d%c", V[i] + 1, i + 1 < V.size()? ' ': '\n');
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        V.push_back(i);
    }
    if (k == 0) {
        Print(V);
        return 0;
    }
    tlen++;
    Solve(V, Maxb - 1);
    Print(res);
    return 0;
}