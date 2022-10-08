
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

const int N = 4005;
int n;

struct child {
    ll v, d, p;
    int idx;
    child(ll v, ll d, ll p, int idx): v(v), d(d), p(p), idx(idx) {}
};

ll v, d, p;
vector<child*> ve;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> v >> d >> p;
        ve.push_back(new child(v, d, p, i));
    }
    vi ans;
    while(!ve.empty()) {
        ans.push_back(ve[0]->idx);
        ve[0]->p = -1;
        rep(i, 1, sz(ve)) {
            ve[i]->p -= max(0LL, ve[0]->v - i + 1);
            if(ve[i]->p < 0) {
                rep(j, i + 1, sz(ve)) {
                    ve[j]->p -= ve[i]->d;
                }
            }
        }
        ve.erase(stable_partition(all(ve), [&](child *c) {
            return c->p >= 0;
        }), ve.end());
    }
    cout << sz(ans) << '\n';
    for(int x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}