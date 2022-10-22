#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 500005;

int n;
int L[Maxn], R[Maxn];
int par[Maxn], siz[Maxn];
vector <iii> seq;
set <ii> S;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &L[i], &R[i]);
        seq.push_back(iii(ii(L[i], R[i]), i));
        par[i] = i; siz[i] = 1;
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++) {
        set <ii>::iterator it = S.lower_bound(ii(seq[i].first.first, 0));
        while (it != S.end() && it->first < seq[i].first.second) {
            if (!unionSet(it->second, seq[i].second)) { printf("NO\n"); return 0; }
            it++;
        }
        S.insert(ii(seq[i].first.second, seq[i].second));
    }
    if (siz[getPar(1)] != n) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}