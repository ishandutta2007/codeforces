#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int maxn = 1000100;

int n, m;
vector<vector<int> > ans;
piii vs[maxn]; int vsze;
int mr[maxn], mc[maxn], ma[maxn];
vector<int> vr[maxn], vc[maxn];
int sr[maxn], sc[maxn], srs, scs;

int par[maxn];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }

void merge(int a, int b) { par[getpar(a)] = getpar(b); }

int id(int r, int c) { return r + c * n; }

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    ans.resize(n, vector<int>());
    for (int i = 0; i < n; i++)
        ans[i].resize(m, -1);

    for (int i = 0; i < n * m; i++) par[i] = i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            vs[vsze++] = piii(x, pii(i, j));
        }

    sort(vs, vs + vsze);

    for (int i = 0, j; i < vsze; i = j) {
        for (j = i; j < vsze && vs[j].A == vs[i].A; j++);
        
        srs = scs = 0;
        for (int k = i; k < j; k++) {
            int r = vs[k].B.A, c = vs[k].B.B;
            sr[srs++] = r, sc[scs++] = c;
            vr[r].push_back(c);
            vc[c].push_back(r);
        }

        sort(sr, sr + srs); srs = unique(sr, sr + srs) - sr;
        sort(sc, sc + scs); scs = unique(sc, sc + scs) - sc;
        
        for (int k = 0; k < srs; k++) {
            int r = sr[k];
            sort(vr[r].begin(), vr[r].end());
            for (int l = 0; l < vr[r].size(); l++) {
                if (l > 0) merge(id(r, vr[r][l]), id(r, vr[r][l - 1]));
                if (l + 1 < vr[r].size()) merge(id(r, vr[r][l]), id(r, vr[r][l + 1]));
            }
        }

        for (int k = 0; k < scs; k++) {
            int c = sc[k];
            sort(vc[c].begin(), vc[c].end());
            for (int l = 0; l < vc[c].size(); l++) {
                if (l > 0) merge(id(vc[c][l], c), id(vc[c][l - 1], c));
                if (l + 1 < vc[c].size()) merge(id(vc[c][l], c), id(vc[c][l + 1], c));
            }
        }

        for (int k = i; k < j; k++) {
            int r = vs[k].B.A, c = vs[k].B.B;
            int d = id(r, c);
            ma[getpar(d)] = max(ma[getpar(d)], max(mr[r], mc[c]));
        }

        for (int k = i; k < j; k++) {
            int r = vs[k].B.A, c = vs[k].B.B;
            int d = id(r, c);
            ans[r][c] = ma[getpar(d)] + 1;
            mr[r] = mc[c] = ans[r][c];
        }

        for (int k = 0; k < srs; k++) vr[sr[k]].clear();
        for (int k = 0; k < scs; k++) vc[sc[k]].clear();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
}