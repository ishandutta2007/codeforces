#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxb = 15;

int n;
int a[Maxn];
int par[1 << Maxb];
vector <vector <int> > res;

void addMask(int mask)
{
    vector <int> add;
    for (int i = 0; i < n; i++)
        if (par[mask] & 1 << i) add.push_back(i + 1);
    res.push_back(add);
}

void Flip(int x) { a[x] = 1 - a[x]; }

void addSimple(int a1, int a2, int a3)
{
    Flip(a1); Flip(a2); Flip(a3);
    vector <int> add(3);
    add[0] = a1 + 1; add[1] = a2 + 1; add[2] = a3 + 1;
    res.push_back(add);
}

void Eliminate(int ind)
{
    if (ind + 6 < n) {
        addSimple(ind, ind + 3, ind + 6);
        addSimple(ind + 3, ind + 4, ind + 5);
        addSimple(ind + 4, ind + 5, ind + 6);
    } else {
        addSimple(ind - 6, ind - 3, ind);
        addSimple(ind - 5, ind - 4, ind - 3);
        addSimple(ind - 6, ind - 5, ind - 4);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (n <= 15) {
        par[0] = -1;
        vector <int> Q; Q.push_back(0);
        for (int i = 0; i < Q.size(); i++) {
            int mask = Q[i];
            for (int a = 0; a < n; a++)
                for (int b = a + 1; b < n; b++) {
                    int c = b + (b - a);
                    if (c < n) {
                        int nmask = (mask ^ (1 << a) ^ (1 << b) ^ (1 << c));
                        if (!par[nmask]) {
                            par[nmask] = ((1 << a) ^ (1 << b) ^ (1 << c));
                            Q.push_back(nmask);
                        }
                    }
                }
        }
        int mask = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 1) mask |= 1 << i;
        if (!par[mask]) { printf("NO\n"); return 0; }
        while (mask) {
            addMask(par[mask]);
            mask ^= par[mask];
        }
    } else {
        vector <int> seq;
        for (int i = 0; i < n; i++) if (a[i] == 1)
            if (seq.empty()) seq.push_back(i);
            else if (seq.size() == 1)
                    if (i - seq.back() == 1) seq.push_back(i);
                    else {
                        int a = seq.back();
                        int b = 2 * i - a;
                        if (b < n) { addSimple(a, i, b); seq.pop_back(); }
                        else { Eliminate(seq.back()); seq.back() = i; }
                    }
            else if (i - seq.back() == 1) {
                addSimple(seq[0], seq.back(), i);
                seq.clear();
            } else {
                int a = seq.back();
                int b = 2 * i - a;
                if (b < n) { addSimple(a, i, b); seq.pop_back(); }
                else {
                    while (!seq.empty()) {
                        Eliminate(seq.back()); seq.pop_back();
                    }
                    seq.push_back(i);
                }
            }
        while (!seq.empty()) {
            Eliminate(seq.back()); seq.pop_back();
        }
    }
    printf("YES\n");
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
    return 0;
}