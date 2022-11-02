#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = 1000 * 1000 * 1000 + 10;
const int LIM = 1000 * 1000 * 1000;
const int N = 300 * 1000 + 10;
const int OPT = (1 << 30) - 1;
using UI = unsigned int;

bool satisf[N];
set<int> must_have;
int tp[N];
int l[N];
int r[N];
int x[N];
int earliest[N];
int n, m;
int ans[N];

struct Tree {
    vector<int> t;
    int size;

    Tree(int s): t(4 * s + 10, INF), size(s) {}

    void put(int pos, int val) {
        put(0, 0, size - 1, pos, val);
    }

    int get(int l, int r) {
        return get(0, 0, size - 1, l, r);
    }

    void put(int i, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[i] = val;
            return;
        }
        int m = (tl + tr) / 2;
        if (pos <= m)
            put(2 * i + 1, tl, m, pos, val);
        else
            put(2 * i + 2, m + 1, tr, pos, val);
        t[i] = min(t[2 * i + 1], t[2 * i + 2]);
    }

    int get(int i, int tl, int tr, int l, int r) {
        if (l == tl && r == tr)
            return t[i];
        int ml = INF;
        int mr = INF;
        int m = (tl + tr) / 2;
        if (l <= m)
            ml = get(2 * i + 1, tl, m, l, min(r, m));
        if (r > m)
            mr = get(2 * i + 2, m + 1, tr, max(m + 1, l), r);
        return min(ml, mr);
    }
};

void gen_satisf() {
    map<int, set<int>> pos;
    vector<int> cur(n, -1);
    for (int i = 0; i < m; i++)
        if (tp[i] == 2) {
            if (cur[l[i]] != -1)
                pos[cur[l[i]]].erase(l[i]);
            cur[l[i]] = x[i];
            pos[cur[l[i]]].insert(l[i]);
        } else {
            if (!pos.count(x[i]))
                continue;
            auto it = pos[x[i]].lower_bound(l[i]);
            if (it != pos[x[i]].end() && *it <= r[i])
                satisf[i] = true;
        }
}

vector<int> open_at[N];
vector<int> close_at[N];
int bound[N];

void gen_bounds() {
    fill(bound, bound + n, INF);
    for (int i = 0; i < m; i++)
        if (tp[i] == 1) {
            open_at[l[i]].push_back(i);
            close_at[r[i]].push_back(i);
            if (!satisf[i])
                must_have.insert(x[i]);
        }
    Tree tree(m);
    for (int i = 0; i < n; i++) {
        for (int idx : open_at[i])
            tree.put(idx, x[idx]);
        int r = min(m - 1, earliest[i]);
        bound[i] = tree.get(0, r);
        for (int idx : close_at[i])
            tree.put(idx, INF);
    }
}

bool check() {
    Tree tree(n);
    for (int i = 0; i < n; i++)
        tree.put(i, -ans[i]);
    for (int i = 0; i < m; i++)
        if (tp[i] == 2)
            tree.put(l[i], -x[i]);
        else
            if (tree.get(l[i], r[i]) != -x[i])
                return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(earliest, earliest + n, INF);
    for (int i = 0; i < m; i++) {
       cin >> tp[i];
       if (tp[i] == 1) { 
           cin >> l[i] >> r[i] >> x[i];
           l[i]--;
           r[i]--;
        }
        else {
            cin >> l[i] >> x[i];
            l[i]--;
            earliest[l[i]] = min(earliest[l[i]], i);
        }
    }
    gen_satisf();
    gen_bounds();
    //for (int i = 0; i < n; i++)
    //    cout << bound[i] << " ";
   // cout << endl;
    UI remaining = OPT;
    vector<pii> rest;
    for (int i = 0; i < n; i++) 
        if (must_have.count(bound[i])) {
            must_have.erase(bound[i]);
            ans[i] = bound[i];
            remaining &= ~UI(ans[i]);
        } else {
            rest.push_back(pii(-bound[i], i));
        }
    sort(rest.begin(), rest.end());
    for (auto p : rest) {
        int i = p.second;
        int lim = min(LIM, bound[i]);
        UI cur = 0;
        for (int j = 29; j >= 0; j--)
            if ((remaining & (1 << j)) && cur + (1 << j) <= lim)
                cur += (1 << j);
        remaining &= ~cur;
        ans[i] = cur;
    }
    if (!check()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}