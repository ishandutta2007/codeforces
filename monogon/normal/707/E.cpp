
#pragma GCC optimize ("Ofast")
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// rectangle => PIE, so assume it starts at (1, 1)
// sum all ON garlands strictly inside rectangle --- iterate over all garlands
// iterate over all garlands crossing boundary
// might alternate inside/outside
// suppose it ends in rectangle -> add sum
// enter -> subtract prefix. exit -> add prefix

const int N = 2005;
int n, m, k;
bool on[N];
int gar[N][N], idx[N][N];
ll pref[N][N];
vi ve[N];
vector<pii> garland[N];

ll solve(int x, int y) {
    rep(i, 0, k + 1) ve[i].clear();
    rep(i, 1, y + 1) {
        ve[gar[x][i]].push_back(idx[x][i]);
    }
    rep(j, 1, x) {
        ve[gar[j][y]].push_back(idx[j][y]);
    }
    ll ans = 0;
    rep(i, 1, k + 1) {
        if(!on[i]) continue;
        for(int j : ve[i]) {
            // if enter
            if(j > 1 && (garland[i][j - 1].first > x || garland[i][j - 1].second > y)) {
                ans -= pref[i][j - 1];
            }
            // if exit
            if(j < sz(garland[i]) - 1 && (garland[i][j + 1].first > x || garland[i][j + 1].second > y)) {
                ans += pref[i][j];
            }
        }
        if(garland[i].back().first <= x && garland[i].back().second <= y) {
            ans += pref[i][sz(garland[i]) - 1];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 1, k + 1) {
        int len;
        cin >> len;
        garland[i].emplace_back(0, 0);
        rep(j, 1, len + 1) {
            int x, y, w;
            cin >> x >> y >> w;
            gar[x][y] = i;
            idx[x][y] = j;
            pref[i][j] = w + pref[i][j - 1];
            garland[i].emplace_back(x, y);
        }
        on[i] = true;
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        if(s == "SWITCH") {
            int i;
            cin >> i;
            on[i] = !on[i];
        }else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << solve(x2, y2) - solve(x2, y1 - 1) - solve(x1 - 1, y2) + solve(x1 - 1, y1 - 1) << '\n';
        }
    }
}