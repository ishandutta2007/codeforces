#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <ios>

using namespace std;

struct data {
    int n, c, t, i;
    data(int _n, int _c, int _t, int _i) : n(_n), c(_c), t(_t), i(_i) {}
};

const int maxn = 50010;

int n, m;
vector<data> adj[maxn];
vector<int> vadj[8 * maxn], tadj[8 * maxn];
int indeg[8 * maxn];
int num;

bool cmp(data d1, data d2) { return d1.c < d2.c; }

void add(int a, int b) {
    vadj[a].push_back(b);
}

void add2(int a, int b) {
    add((a + 4 * maxn) % (8 * maxn), b);
    add((b + 4 * maxn) % (8 * maxn), a);
}

void go(vector<int> v) {
    while (v.size() > 1) {
        vector<int> w;
        int s = v.size();
        for (int i = 0; i < s / 2; i++) {
            add2(v[2 * i] + 4 * maxn, v[2 * i + 1] + 4 * maxn);
            add2(v[2 * i] + 4 * maxn, num);
            add2(v[2 * i + 1] + 4 * maxn, num);
            w.push_back(num);
            num++;
            if (num >= 4 * maxn) exit(0);
        }

        if (s & 1) w.push_back(v[s - 1]);
        v = w;
    }
}

bool in[8 * maxn];
int ind[8 * maxn], lowlink[8 * maxn], cnt;
int stk[8 * maxn], stksze;
int par[8 * maxn];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) { par[getpar(a)] = getpar(b); }

void dfs(int cur) {
    ind[cur] = lowlink[cur] = cnt++;
    stk[stksze++] = cur, in[cur] = 1;
    for (int i : vadj[cur]) {
        if (ind[i] == -1) {
            dfs(i);
            lowlink[cur] = min(lowlink[cur], lowlink[i]);
        } else if (in[i]) lowlink[cur] = min(lowlink[cur], ind[i]);
    }

    if (ind[cur] == lowlink[cur]) {
        while (stk[stksze - 1] != cur) {
            merge(stk[stksze - 1], cur);
            in[stk[stksze - 1]] = 0;
            stksze--;
        }
        assert(stk[stksze - 1] == cur);
        in[cur] = 0;
        stksze--;
    }
}

int ord[8 * maxn], ocnt;

void dfs2(int cur) {
    ord[cur] = ocnt++;
    for (int i : tadj[cur]) {
        indeg[i]--;
        if (!indeg[i]) dfs2(i);
    }
}

int ans[maxn], sans;

bool check(int mt, bool pans = 0) {
    for (int i = 0; i < 8 * maxn; i++) vadj[i].clear();
    num = m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            data d = adj[i][j];
            if (d.t > mt) add(d.i, d.i + 4 * maxn);

            if (j && adj[i][j].c == adj[i][j - 1].c) {
                //cout << i << ' ' << d.n << ' ' << adj[i][j - 1].n << endl;
                //cout << i + 1 << ' ' << d.i << ' ' << adj[i][j - 1].i << endl;
                add2(d.i, adj[i][j - 1].i);
            }
        }

        vector<int> v;
        for (data d : adj[i]) v.push_back(d.i);
        go(v);
/*
        for (int j = 0; j < v.size(); j++)
            for (int k = j + 1; k < v.size(); k++)
                add2(v[j] + 4 * maxn, v[k] + 4 * maxn);
*/
    }

    for (int i = 0; i < 8 * maxn; i++)
        par[i] = i, ind[i] = -1;

    for (int i = 0; i < 8 * maxn; i++)
        if (ind[i] == -1)
            dfs(i);

    for (int i = 0; i < 4 * maxn; i++)
        if (getpar(i) == getpar(i + 4 * maxn)) {
            //cout << i << endl;
            return 0;
        }

    if (pans) {
        memset(indeg, 0, sizeof(indeg));
        for (int i = 0; i < 8 * maxn; i++) {
            int x = getpar(i);
            for (int j : vadj[i])
                if (x != getpar(j)) {
                    tadj[x].push_back(getpar(j));
                    indeg[getpar(j)]++;
                }
        }
/*
        for (int i = 0; i < 8 * maxn; i++)
            if (tadj[i].size()) {
                cout << i + 1 << ' ';
                for (int j : tadj[i]) cout << j + 1 << ' ';
                cout << endl;
            }
*/
        memset(ord, -1, sizeof(ord));
        for (int i = 0; i < 8 * maxn; i++)
            if (!indeg[i] && ord[i] == -1)
                dfs2(i);
/*
        for (int i = 0; i < 8 * maxn; i++)
            if (indeg[i] > 0)
                cout << i + 1 << endl;
*/
        for (int i = 0; i < m; i++) {
            //cout << ord[getpar(i)] << ' ' << ord[getpar(i + 4 * maxn)] << endl;
            if (ord[getpar(i)] > ord[getpar(i + 4 * maxn)])
                ans[sans++] = i + 1;
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        a--, b--;
        adj[a].push_back(data(b, c, t, i));
        adj[b].push_back(data(a, c, t, i));
    }

    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);

        int num = 0;
        for (int j = 0; j < adj[i].size(); j++)
            if (j && adj[i][j].c == adj[i][j - 1].c)
                num++;

        if (num > 1) {
            cout << "No\n";
            return 0;
        }
    }

    int lo = 0, hi = 1e9 + 5;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    if (lo == 1e9 + 5) cout << "No\n";
    else {
        cout << "Yes\n";
        check(lo, 1);
        cout << lo << ' ' << sans << '\n';
        for (int i = 0; i < sans; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}