#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define a first
#define b second
const int N = 1e5 + 5;
int n, m, lvl[N], par[N], dep[N];
pair<int, int> d[N];
vector<vector<int> > all;
vector<int> g[N];
vector<pair<vector<int>, int> > all1;
bool cmp(pair<int, int> a, pair<int, int> b) {
    int d1 = min(a.b - a.a - 1, n - 2 - (a.b - a.a - 1));
    int d2 = min(b.b - b.a - 1, n - 2 - (b.b - b.a - 1));
    return d1 < d2;
}


bool cmp1(pair<vector<int>, int> &a, pair<vector<int>, int> &b) {
    vector<int> p1 = a.first, p2 = b.first;
    if (p1[0] != p2[0])
        return p1[0] < p2[0];
    if (p1[1] != p2[1])
        return p1[1] < p2[1];
    return p1[2] < p2[2];
}


int dfs(int v, int sz, int &center, int par = 0) {
    int sum = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (lvl[g[v][i]] == 0 && g[v][i] != par)
            sum += dfs(g[v][i], sz, center, v);
    if (center == -1 && 2 * sum >= sz)
        center = v;
    return sum;
}

void build(int v, int dep, int p = 0) {
    int center = -1, tmp = -1;
    dfs(v, dfs(v, tmp, tmp), center);
    //cout << v << ' ' << center<<endl;
    lvl[center] = dep;
    par[center] = p;
    for (int i = 0; i < g[center].size(); i++)
        if (lvl[g[center][i]] == 0)
            build(g[center][i], dep + 1, center);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> d[i].a >> d[i].b;
        if (d[i].a > d[i].b)
            swap(d[i].a, d[i].b);
    }


    sort(d + 1, d + m + 1, cmp);
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 1; i <= m; i++) {
        int a = d[i].a, b = d[i].b;
        vector<int> c;
        if (b - a - 1 <= n - 2 - (b - a - 1)) {
            c.pb(a);
            auto it = s.upper_bound(a);
            while (*it != b) {
                c.pb(*it);
                it++;
            }
            c.pb(b);
            for (int j = 1; j + 1 < c.size(); j++)
                s.erase(c[j]);
            all.pb(c);
        } else {
            while (*s.begin() != a)
            {
                c.pb(*s.begin());
                s.erase(s.begin());
            }
            c.pb(a);
            c.pb(b);
            auto it = s.upper_bound(b);
            while (it != s.end()) {
                c.pb(*it);
                it++;
                s.erase(c.back());
            }
            all.pb(c);
        }
    }
    vector<int> c;
    while (s.size() != 0) {
        c.pb(*s.begin());
        s.erase(*s.begin());
    }
    all.pb(c);

    map<pair<int, int>, int> m;

    for (int i = 0; i < all.size(); i++) {
        for (int j = 0; j + 1 < all[i].size(); j++)
            if (all[i][j] == all[i][j + 1] - 1)
                continue;
            else if (m[{all[i][j], all[i][j + 1]}] == 0)
                    m[{all[i][j], all[i][j + 1]}] = i + 1;
            else {
                int x = m[{all[i][j], all[i][j + 1]}];
                g[x].pb(i + 1);
                g[i + 1].pb(x);
            }
        if (all[i].back() == n && all[i][0] == 1)
            continue;
        else if (m[{all[i][0], all[i].back()}] == 0)
                    m[{all[i][0], all[i].back()}] = i + 1;
            else {
                int x = m[{all[i][0], all[i].back()}];
                g[x].pb(i + 1);
                g[i + 1].pb(x);
            }

    }
    build(1, 1);
   /* for (int i = 0; i <all.size(); i++) {
        for (int j = 0; j < all[i].size(); j++)
            cout << all[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= all.size(); i++) {
        for (int j = 0; j < g[i].size(); j++)
            cout << g[i][j] << ' ';
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= all.size(); i++)
        cout << lvl[i] << ' ';
    cout << endl;
*/
    for (int i = 0; i < all.size(); i++) {
        sort(all[i].rbegin(), all[i].rend());
        all1.pb({all[i], i + 1});
    }
    sort(all1.begin(), all1.end(), cmp1);
    /*for (int i = 0; i < all1.size(); i++) {
        for (int j = 0; j < all1[i].first.size(); j++)
            cout << all1[i].first[j] << ' ';
        cout << endl;
    }*/
    for (int i = 0; i < all1.size(); i++)
        cout << lvl[all1[i].second] << ' ';
    return 0;
}