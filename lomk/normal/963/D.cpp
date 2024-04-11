/*input
abbb
7
4 b
1 ab
3 bb
1 abb
2 bbb
1 a
2 abbb


aaaaa
5
3 a
3 aa
2 aaa
3 aaaa
1 aaaaa

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#define debug(x...) {cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
const int N = 1e5 + 5;

struct ahoCorasick {
    struct Node {
        int child[26], fail, term;
        vector<int> id;
        Node(): fail(0), term(0) {
            memset(child, 0, sizeof(child));
        }
    };
    vector<Node> a;
    vector<vector<int> > id;
    int add(string s, int _id) {
        int u = 0;
        for (auto it : s) {
            if (a[u].child[it - 'a'] == 0) {
                a.push_back(Node());
                a[u].child[it - 'a'] = a.size() - 1;
            }
            u = a[u].child[it - 'a'];
        }
        id[u].push_back(_id);
        return u;
    }
    void makeAho() {
        queue<int> q({0});
        while (!q.empty()) {
            int u = q.front(); q.pop();
            loop(i, 0, 25) {
                int v = a[u].child[i]; int fv = a[a[u].fail].child[i];
                if (v == 0) {a[u].child[i] = fv; continue;}
                if (fv != v) {
                    a[v].fail = fv;
                    a[v].term = (id[fv].size() ? fv : a[fv].term);
                }
                q.push(v);
            }
        }
    }
    ahoCorasick(): id(N) {a.push_back(Node());}
    void findAllOccur(string &s, vector<vector<int> > &app) {
        int u = 0;
        loop(i, 0, s.size() - 1) {
            auto c = s[i]; u = a[u].child[c - 'a'];
            int v = u;
            while (v != 0) {
                for (auto it : id[v]) app[it].push_back(i);
                v = a[v].term;
            }
        }
    }
} Aho; // remeber to run makeAho

vector<pair<int, string> > query;
vector<vector<int> > app(N);
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a;
    cin >> a;
    int q; cin >> q;
    loop(i, 1, q) {
        int need; string s;
        cin >> need >> s;
        query.push_back({need, s});
        Aho.add(s, i - 1);
    }
    Aho.makeAho();
    Aho.findAllOccur(a, app);
    loop(i, 0, q - 1) {
        if (app[i].size() < query[i].fi) {
            cout << -1 << endl;
            continue;
        }
        int ans = 1e9;
        loop(j, query[i].fi - 1, app[i].size() - 1) {
            int R = app[i][j];
            int L = app[i][j - query[i].fi + 1] - query[i].se.size() + 1;
            ans = min(ans, R - L + 1);
        }
        cout << ans << endl;
    }
}