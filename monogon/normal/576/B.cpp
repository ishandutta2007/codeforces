
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

// 3 1 2, impossible? 1->3, 2->1, 3->2
// leaves should be permuted.
// with 3 nodes, there is only the path, so the middle node would have to stay put
// If there is a fixed point of the permutation, we can make it the root and everything else is a leaf.
// (1 4) (2 3)
// 4 -- 1
// |    |
// 2    3

// (1 2 3 4)
// If n >= 3, there is a non-leaf. Since leaves are mapped to leaves,
// there should not be only one cycle.

// Guess: cycles of at most length 2 can exist.

// 1 --- 2
// |     |
// 3,4  5,6

// (1 2) (3 5 4 6)
// New guess: one cycle should be length 2, and other cycles should be even.

const int N = 1e5 + 5;
int n, p[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> p[i];
    }
    vector<vi> ve;
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            vi cyc;
            int j = i;
            while(!vis[j]) {
                vis[j] = true;
                cyc.push_back(j);
                j = p[j];
            }
            ve.push_back(cyc);
            if(sz(cyc) == 1) {
                cout << "YES\n";
                rep(j, 1, n + 1) {
                    if(j != i) {
                        cout << i << ' ' << j << '\n';
                    }
                }
                return 0;
            }
        }
    }
    bool flag = false;
    int idx = 0;
    for(vi v : ve) {
        if(sz(v) % 2 == 1) {
            cout << "NO\n";
            return 0;
        }
        if(sz(v) == 2) {
            flag = true;
            idx = v[0];
        }
    }
    if(!flag) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << idx << ' ' << p[idx] << '\n';
    for(vi v : ve) {
        if(v[0] != idx && v[0] != p[idx]) {
            bool b = false;
            for(int x : v) {
                cout << (b ? idx : p[idx]) << ' ' << x << '\n';
                b = !b;
            }
        }
    }
}