#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100100;

int n, c[MAXN], s[MAXN];
set<pii> st[2];

struct edge {
    int a, b, c;
    edge() {}
    edge(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
} ans[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> c[i] >> s[i];
        st[c[i]].insert(pii(s[i], i));
    }

    for (int i=0; i<n-1; i++) {
        pii p1 = *st[0].begin(), p2 = *st[1].begin();
        st[0].erase(st[0].begin());
        st[1].erase(st[1].begin());
        if (p1.first < p2.first || p1.first == p2.first && st[1].size() < st[0].size()) {
            ans[i] = edge(p1.second+1, p2.second+1, p1.first);
            st[1].insert(pii(p2.first-p1.first, p2.second));
        } else {
            ans[i] = edge(p1.second+1, p2.second+1, p2.first);
            st[0].insert(pii(p1.first-p2.first, p1.second));
        }
    }

    for (int i=0; i<n-1; i++)
        cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << '\n';
    return 0;
}