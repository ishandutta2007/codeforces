#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

typedef pair<ii, ii> pii; 
typedef vector<pii> vp;

int n, m, x, y;
vii a, b;
vp c;
map<ii, set<int>> ma, mb; 
set<int> res;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        a.emplace_back(x, y);
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        b.emplace_back(x, y);
    }

    for (ii &aa : a)
        for (ii &bb : b) {
            if (aa.fi != bb.fi || aa.se != bb.se) {
                if (aa.fi == bb.fi || aa.fi == bb.se) {
                    c.emplace_back(aa, bb);
                    res.insert(aa.fi);
                    ma[aa].insert(aa.fi);
                    mb[bb].insert(aa.fi);
                }
                if (aa.se == bb.fi || aa.se == bb.se) {
                    c.emplace_back(aa, bb);
                    res.insert(aa.se);
                    ma[aa].insert(aa.se);
                    mb[bb].insert(aa.se);
                }
            }
        }

    if (res.size() == 1) {
        cout << *res.begin() << endl;
        return 0;
    }

    bool fa = 1, fb = 1;

    for (pii &p : c) {
        fa &= ma[p.fi].size() == 1;
        fb &= mb[p.se].size() == 1;
    }

    if (fa && fb)
        cout << 0 << endl;
    else
        cout << -1 << endl;

    return 0;
}