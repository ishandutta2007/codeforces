#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int T;
int n;
set <int> mem[Maxn];
set <int> S[Maxn];
vector <int> inset[Maxn];
int P[Maxn];
int inp[Maxn];

void Remove(int val)
{
    for (int i = 0; i < inset[val].size(); i++) {
        int ind = inset[val][i];
        S[ind].erase(val);
    }
}

int getNext()
{
    set <int> good;
    for (int i = 0; i < n - 1; i++)
        if (S[i].size() == 1) good.insert(*S[i].begin());
    return good.size() == 1? *good.begin(): -1;
}

bool Solve(int fir)
{
    for (int i = 0; i < n - 1; i++)
        S[i] = mem[i];
    Remove(fir);
    P[0] = fir;
    for (int i = 1; i < n; i++) {
        P[i] = getNext();
        if (P[i] == -1) return false;
        Remove(P[i]);
    }
    for (int i = 0; i < n; i++)
        inp[P[i]] = i;
    for (int i = 0; i < n - 1; i++) {
        int mn = Maxn, mx = -Maxn;
        for (auto num: mem[i]) {
            mn = min(mn, inp[num]);
            mx = max(mx, inp[num]);
        }
        if (mx - mn + 1 != mem[i].size())
            return false;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            inset[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int k; scanf("%d", &k);
            mem[i].clear();
            while (k--) {
                int a; scanf("%d", &a);
                mem[i].insert(a);
                inset[a].push_back(i);
            }
        }
        int i = 1;
        while (!Solve(i)) i++;
        for (int i = 0; i < n; i++)
            printf("%d%c", P[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}