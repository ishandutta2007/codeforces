#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

vector <int> un;
int n;
int a[Maxn], b[Maxn];
multiset <int> neigh[Maxn];
vector <int> seq;

void removeNeigh(int a, int b)
{
    multiset <int>::iterator it = neigh[a].find(b);
    neigh[a].erase(it);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &b[i]);
        if (a[i] > b[i]) { printf("-1\n"); return 0; }
        un.push_back(b[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n - 1; i++) {
        a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        b[i] = lower_bound(un.begin(), un.end(), b[i]) - un.begin();
        neigh[a[i]].insert(b[i]);
        neigh[b[i]].insert(a[i]);
    }
    vector <int> odd;
    for (int i = 0; i < un.size(); i++) if (neigh[i].size() % 2)
        odd.push_back(i);
    if (odd.size() != 2 && odd.size() != 0) { printf("-1\n"); return 0; }
    vector <int> S;
    int v = odd.empty()? 0: odd[0];
    while (!neigh[v].empty() || !S.empty())
        if (neigh[v].empty()) {
            seq.push_back(v);
            v = S.back(); S.pop_back();
        } else {
            S.push_back(v);
            int u = *neigh[v].begin();
            removeNeigh(v, u);
            removeNeigh(u, v);
            v = u;
        }
    seq.push_back(v);
    if (seq.size() != n) { printf("-1\n"); return 0; }
    for (int i = 0; i < seq.size(); i++)
        printf("%d%c", un[seq[i]], i + 1 < seq.size()? ' ': '\n');
    return 0;
}