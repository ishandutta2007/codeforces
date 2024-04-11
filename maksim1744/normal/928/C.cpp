#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int mx = 1000000000;

struct proj
{
    int v;
    string s;
    int d;
    int key;
    proj() {}
    proj (string ss, int k, int dd)
    {
        key = k;
        d = dd;
        s = "";
        int i = 0;
        while (ss[i] != ' ') {
            s += ss[i];
            i++;
        }
        i++;
        int p10 = 1;
        v = 0;
        for (int j = ss.length() - 1; j >= i; j--) {
            v += p10 * (ss[j] - '0');
            p10 *= 10;
        }
    }
};

bool comp(proj a, proj b)
{
    if (a.s != b.s) {
        return a.s < b.s;
    }
    if (a.d != b.d) {
        return a.d < b.d;
    }
    return a.v > b.v;
}

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > g(n);
    vector< string > p(n);
    map<string, int> m;
    int lst = 0;
    for (int i = 0; i < n; i++) {
        string s, s1;
        getline(cin, s1);
        getline(cin, s1);
        if (m.count(s1) == 0) {
            m[s1] = lst;
            p[lst] = s1;
            lst++;
        }
        int t;
        cin >> t;
        getline(cin, s);
        for (int j = 0; j < t; j++) {
            getline(cin, s);
            if (m.count(s) == 0) {
                m[s] = lst;
                p[lst] = s;
                lst++;
            }
            g[m[s1]].push_back(m[s]);
        }
    }
    vector<proj> pr(n);
    for (int i = 0; i < n; i++) {
        pr[i] = proj(p[i], i, mx);
    }
    map<string, pair<int, int> > ds;
    vector<string> ss;
    for (int i = 0; i < n; i++) {
        if (ds.count(pr[i].s) == 0) {
            ds[pr[i].s] = make_pair(mx, i);
            ss.push_back(pr[i].s);
        }
    }
    vector<bool> used(n, false);
    queue<int> q;
    vector<int> v1;
    vector<int> v2;
    vector<proj> ans;
    int d = 1;
    ds[pr[0].s] = make_pair(0, 0);
    v1.push_back(0);
    while (v1.size() > 0) {
        for (int i = 0; i < v1.size(); i++) {
            int v = v1[i];
            used[v] = true;
            for (int j = 0; j < g[v].size(); j++) {
                int to = g[v][j];
                if (used[to]) {
                    continue;
                }
                if (ds[pr[to].s].first == mx) {
                    ds[pr[to].s] = make_pair(d, to);
                }
                else if (ds[pr[to].s].first < d) {
                    continue;
                }
                else {
                    if (pr[ds[pr[to].s].second].v < pr[to].v) {
                        ds[pr[to].s].second = to;
                    }
                }
            }
        }
        v1.clear();
        for (int i = 0; i < ss.size(); i++) {
            if (d == ds[ss[i]].first) {
                v1.push_back(ds[ss[i]].second);
                ans.push_back(pr[ds[ss[i]].second]);
            }
        }
        d++;
    }
    sort(ans.begin(), ans.end(), comp);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << p[ans[i].key] << endl;
    }
}