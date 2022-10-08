
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// if k = 1, we can do path for n <= 2, else impossible
// upper bound on diameter: path.
// d = n - 1, we can always do if k >= 2

// diameter exactly d, means there is a path of length d
// d edges
// rooted tree with depth at most D with branching factor K
// 

// x -- x -- x -- x -- x
//      |    |    |
//  dpth 0 dpth 1 dpth 0

int n, d, k;
vector<pii> edge;

void buildtree(int x, int num) {
    if(num == 0) return;
    int amt = (num - 1) / (k - 1);
    int j = x + 1;
    rep(i, 0, k - 1) {
        int realamt = amt + (((num - 1) % (k - 1)) > i);
        if(realamt == 0) break;
        edge.emplace_back(x, j);
        buildtree(j, realamt);
        j += realamt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d >> k;
    if(k == 1) {
        if(d == 1 && n == 2) {
            cout << "YES\n" << "1 2\n";
        }else {
            cout << "NO\n";
        }
        return 0;
    }
    if(d >= n) {
        cout << "NO\n";
        return 0;
    }
    rep(i, 1, d + 1) {
        edge.emplace_back(i, i + 1);
    }
    ll node = d + 1;
    rep(i, 1, d + 2) {
        ll dep = min(i - 1, d + 1 - i);
        ll p = 1;
        ll num = 0;
        if(k == 2) {
            num = dep;
        }else {
            for(int dd = 0; node + num < n && dd < dep; dd++) {
                num += p;
                p = p * (k - 1);
            }
        }
        for(int j = 0; j < k - 2 && node < n; j++) {
            ll num2 = min(num, n - node);
            if(num2 > 0) {
                edge.emplace_back(i, node + 1);
                buildtree(node + 1, num2);
                // cout << "building tree of depth " << min(num, n - node) << " at " << i << endl;
                node += num2;
            }
        }
    }
    if(sz(edge) < n - 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto &p : edge) {
        cout << p.fi << ' ' << p.se << '\n';
    }
}