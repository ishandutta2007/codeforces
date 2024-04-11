#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, m;
vector <int> neigh[Maxn], rneigh[Maxn];
int mx, en;
int st[Maxn];
int orig[Maxn];
int cur[Maxn];
int incur[Maxn];
int lef[Maxn], rig[Maxn];
vector <int> hasin[Maxn];
vector <int> good, od, ev, bad;
vector <int> notgood;
int delt[Maxn];
vector <int> seq;
bool tk[Maxn];
int res;

void topSort(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < rneigh[v].size(); i++)
        topSort(rneigh[v][i]);
    seq.push_back(v);
}

void addFrom(const vector <int> &V)
{
    for (int i = 0; i < V.size(); i++) {
        int v = V[i];
        if (lef[v] + 1 < rig[v]) {
            delt[lef[v] + 1]++;
            delt[rig[v]]--;
        }
    }
}

void Process(const vector <int> &totest, int lim)
{
    for (int i = 0; i < seq.size(); i++) {
        int v = seq[i];
        lef[v] = cur[v];
        for (int j = 0; j < rneigh[v].size(); j++) {
            int u = rneigh[v][j];
            lef[v] = max(lef[v], lef[u]);
        }
    }
    for (int i = int(seq.size()) - 1; i >= 0; i--) {
        int v = seq[i];
        rig[v] = cur[v]? cur[v]: mx + 1;
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j];
            rig[v] = min(rig[v], rig[u]);
        }
    }
    fill(delt, delt + mx + 2, 0);
    addFrom(notgood);
    int ways = 0;
    for (int i = 1; i <= mx; i++) {
        ways += delt[i];
        delt[i] = ways;
    }
    for (int i = 0; i < totest.size(); i++) {
        int v = totest[i];
        if (delt[cur[v]] >= lim)
            res++;
    }
    fill(cur, cur + n + 1, 0);
    for (int i = 1; i <= n; i++) if (orig[i] > 0) {
        cur[i] = orig[i];
        incur[cur[i]] = i;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        rneigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        topSort(i);
    for (int i = 0; i < seq.size(); i++) {
        int v = seq[i];
        st[v] = 1;
        for (int j = 0; j < rneigh[v].size(); j++) {
            int u = rneigh[v][j];
            st[v] = max(st[v], st[u] + 1);
        }
        if (st[v] > mx) {
            mx = st[v];
            en = v;
        }
    }
    int v = en;
    while (v != 0) {
        cur[v] = orig[v] = st[v];
        incur[st[v]] = v;
        good.push_back(v);
        int nxt = 0;
        for (int j = 0; j < rneigh[v].size(); j++) {
            int u = rneigh[v][j];
            if (st[u] + 1 == st[v]) { nxt = u; break; }
        }
        v = nxt;
    }
    for (int i = 1; i <= n; i++) if (!orig[i])
        notgood.push_back(i);
    Process(good, 2);
    for (int i = 0; i < notgood.size(); i++) {
        int v = notgood[i];
        if (lef[v] + 2 == rig[v])
            hasin[lef[v] + 1].push_back(v);
        else bad.push_back(v);
    }
    for (int i = 1; i <= mx; i++)
        if (hasin[i].size() == 1)
            if (i % 2) od.push_back(hasin[i][0]);
            else ev.push_back(hasin[i][0]);
        else if (hasin[i].size() > 1)
            for (int j = 0; j < hasin[i].size(); j++)
                bad.push_back(hasin[i][j]);
    res += bad.size();
    for (int i = 1; i <= mx; i += 2)
        if (hasin[i].size() == 1) {
            int v = hasin[i][0];
            cur[v] = i;
            cur[incur[i]] = 0;
            incur[i] = v;
        }
    Process(od, 1);
    for (int i = 2; i <= mx; i += 2)
        if (hasin[i].size() == 1) {
            int v = hasin[i][0];
            cur[v] = i;
            cur[incur[i]] = 0;
            incur[i] = v;
        }
    Process(ev, 1);
    cout << n - res << endl;
    return 0;
}