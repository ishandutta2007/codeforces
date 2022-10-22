#include <bits/stdc++.h>
using namespace std;

const int Maxn = 256;
const int Inf = 1000000000;

vector <vector <int> > Q;
int lft;
int res[Maxn];
vector <int> myres[Maxn];

void Check(int ind, int val, const vector <int> &V)
{
    if (val < res[ind]) {
        if (res[ind] == Inf) lft--;
        res[ind] = val;
        myres[ind] = V;
    }
}

void Add(int c, int a, int k, int b)
{
    printf("lea e%cx, [e%cx + %d*e%cx]\n", c + 'a', a + 'a', k, b + 'a');
}

void Unwrap(vector <int> V)
{
    if (V.size() == 1) return;
    int me = V.back(); V.back() = 0;
    int sava, savb, savk;
    bool found = false;
    for (int a = 0; a < V.size() && !found; a++)
        for (int b = 0; b < V.size() && !found; b++)
            for (int k = 1; k <= 8 && !found; k <<= 1) {
                if (V[a] + k * V[b] == me) {
                    found = true;
                    sava = a; savb = b; savk = k;
                }
            }
    V.pop_back();
    Unwrap(V);
    Add(V.size(), sava, savk, savb);
}

int main()
{
    fill(res, res + Maxn, Inf);
    lft = Maxn - 1;
    vector <int> V = {1};
    Check(1, 0, V);
    Q.push_back(V);
    for (int i = 0; i < Q.size() && lft > 0; i++) {
        V = Q[i];
        set <int> S;
        int lim = V.back();
        V.push_back(0);
        for (int a = 0; a < V.size(); a++)
            for (int b = 0; b < V.size(); b++)
                for (int k = 1; k <= 8; k <<= 1) {
                    int val = V[a] + k * V[b];
                    if (lim < val && val < Maxn)
                        S.insert(val);
                }
        for (auto it: S) {
            V.back() = it;
            Check(it, int(V.size()) - 1, V);
            Q.push_back(V);
        }
    }
    int n; scanf("%d", &n);
    printf("%d\n", res[n]);
    Unwrap(myres[n]);
    return 0;
}