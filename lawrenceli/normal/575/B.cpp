#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int maxn = 100100;
const int maxk = 1000100;
const int mod = 1e9 + 7;

int n;
vector<pii> adj[maxn];
int pw2[maxk];

int k;
int qx[maxk], qy[maxk], qz[maxk];
vector<int> qadj[maxn];

int par[maxn], rnk[maxn], root[maxn];
int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) {
    a = getpar(a), b = getpar(b);
    root[a] = root[b];
    if (rnk[a] > rnk[b]) swap(a, b);
    par[a] = b;
    if (rnk[a] == rnk[b]) rnk[b]++;
}

void dfs(int cur, int p=-1) {
    for (pii x : adj[cur]) {
        if (x.fi == p) continue;
        dfs(x.fi, cur);
        merge(x.fi, cur);
    }

    for (int i : qadj[cur]) {
        int x = qx[i] == cur ? qy[i] : qx[i];
        qz[i] = root[getpar(x)];
    }
}

int num1[maxn], num2[maxn];
int ans;

pii dfs2(int cur, int p=-1, int st=0) {
    pii ret = pii(num1[cur], num2[cur]);
    for (pii x : adj[cur])
        if (x.fi == p && x.se == 0)
            st = 1;

    for (pii x : adj[cur]) {
        if (x.fi == p) continue;
        pii res;
        if (x.se == 0) res = dfs2(x.fi, cur, 2);
        else res = dfs2(x.fi, cur, 0);
        ret.fi += res.fi, ret.se += res.se;
    }

    if (st == 1) {
        int add = (pw2[ret.fi]+mod-1)%mod;
        ans = (ans + add) % mod;
    } else if (st == 2) {
        int add = (pw2[ret.se]+mod-1)%mod;
        ans = (ans + add) % mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    pw2[0] = 1;
    for (int i=1; i<maxk; i++) pw2[i] = pw2[i-1]*2%mod;

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        if (x == 0) {
            adj[a].push_back(pii(b, 1));
            adj[b].push_back(pii(a, 1));
        } else {
            adj[a].push_back(pii(b, 1));
            adj[b].push_back(pii(a, 0));
        }
    }

    cin >> k;
    int cur = 1;
    for (int i=0; i<k; i++) {
        cin >> qx[i];
        qy[i] = cur;
        qadj[qx[i]].push_back(i);
        qadj[qy[i]].push_back(i);
        cur = qx[i];
    }

    for (int i=0; i<maxn; i++) par[i] = root[i] = i;

    dfs(1);

    cur = 1;
    for (int i=0; i<k; i++) {
        int x = qx[i], y = qz[i];
        num1[cur]++, num1[y]--;
        num2[x]++, num2[y]--;
        cur = x;
    }

    dfs2(1);

    cout << ans << '\n';
}