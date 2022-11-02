#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200100;

int n[2], q, qk[MAXN], x[MAXN], par[2][MAXN], sze[2][MAXN];
bool cut[2][MAXN];
multiset<int> st[2];
ll ans[MAXN];

int getpar(int k, int a) { return par[k][a] == a ? a : par[k][a] = getpar(k, par[k][a]); }

void merge(int k, int a, int b) {
    a = getpar(k, a), b = getpar(k, b);
    if (a == b) return;
    st[k].erase(st[k].find(sze[k][a]));
    st[k].erase(st[k].find(sze[k][b]));
    par[k][a] = b;
    sze[k][b] += sze[k][a];
    st[k].insert(sze[k][b]);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n[0] >> n[1] >> q;
    for (int i=0; i<q; i++) {
        char c;
        cin >> c >> x[i];
        qk[i] = (c == 'V' ? 0 : 1);
        cut[qk[i]][x[i]] = 1;
    }

    for (int k=0; k<2; k++)
        for (int i=0; i<n[k]; i++) {
            par[k][i] = i;
            sze[k][i] = 1;
            st[k].insert(1);
        }

    for (int k=0; k<2; k++)
        for (int i=0; i<n[k]-1; i++) {
            if (!cut[k][i+1]) merge(k, i, i+1);
        }

    for (int i=q-1; i>=0; i--) {
        ans[i] = 1LL * (*st[0].rbegin()) * (*st[1].rbegin());
        merge(qk[i], x[i]-1, x[i]);
    }

    for (int i=0; i<q; i++) cout << ans[i] << '\n';
}