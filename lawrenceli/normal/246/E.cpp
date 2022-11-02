#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 100100;

int n;
string s[MAXN];
int num[MAXN], p[MAXN];
vector<int> adj[MAXN];

int m;
struct qdata {
    int v, k, id;
} arr[MAXN];

vector<qdata> qadj[MAXN];

map<string, int> mp_comp;
int cnt;

vector<int> root;

int dep[MAXN];
int ans[MAXN];

void dfs1(int cur, int p) {
    dep[cur] = dep[p] + 1;
    for (int i=0; i<adj[cur].size(); i++)
        dfs1(adj[cur][i], cur);
}

struct data {
    int sze;
    map<int, int> mp;
    set<pii> st; //num, depth
    void add(pii p) {
        if (st.count(p)) return;
        sze ++;
        mp[p.se] ++;
        st.insert(p);
    }
};

data* merge(data* d1, data* d2) {
    if (d1->sze > d2->sze) swap(d1, d2);
    for (typeof(d1->st.begin()) it = d1->st.begin(); it != d1->st.end(); it++)
        d2->add(*it);
    return d2;
}

data* dfs(int cur) {
    data* ret = new data();
    ret->add(pii(num[cur], dep[cur]));
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        data* res = dfs(nxt);
        ret = merge(ret, res);
    }
    for (int i=0; i<qadj[cur].size(); i++) {
        qdata dat = qadj[cur][i];
        ans[dat.id] = ret->mp[dep[cur] + dat.k];
    }
    return ret;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> p[i];
        p[i] --;
        if (p[i] >= 0) adj[p[i]].push_back(i);
        else root.push_back(i);
        mp_comp[s[i]] = 0;
    }

    for (typeof(mp_comp.begin()) it = mp_comp.begin(); it != mp_comp.end(); it++)
        mp_comp[it->fi] = cnt++;

    for (int i=0; i<n; i++)
        num[i] = mp_comp[s[i]];

    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> arr[i].v >> arr[i].k;
        arr[i].v--; arr[i].id = i;
        qadj[arr[i].v].push_back(arr[i]);
    }

    for (int i=0; i<root.size(); i++)
        dfs1(root[i], root[i]);
    for (int i=0; i<root.size(); i++)
        dfs(root[i]);

    for (int i=0; i<m; i++)
        cout << ans[i] << '\n';

    return 0;
}