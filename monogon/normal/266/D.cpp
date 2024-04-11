
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

const int N = 205, M = N * N;
const ll INF = LLONG_MAX;
const double EPS = 0.1;
int n, m, a[M], b[M];
ll w[M], dist[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    rep(i, 0, m) {
        cin >> a[i] >> b[i] >> w[i];
        dist[b[i]][a[i]] = dist[a[i]][b[i]] = min(dist[a[i]][b[i]], w[i]);
    }
    rep(k, 1, n + 1) rep(i, 1, n + 1) rep(j, 1, n + 1) {
        if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
        }
    }
    double ans = INF;
    rep(i, 0, m) {
        set<pair<double, double>> s;
        double val = INF;
        double d1max = 0, d2max = 0;
        vector<pair<double, double>> ve;
        rep(v, 1, n + 1) {
            ll d1 = dist[v][a[i]];
            ll d2 = dist[v][b[i]];
            d1max = max(d1max, 1.0 * d1);
            d2max = max(d2max, 1.0 * d2);
            // consider function min(d1 + x, d2 + w - x)
            // midpoint at d1 + x = d2 + w - x
            // x = (d2 - d1 + w) / 2
            double x = 0.5 * (d2 - d1 + w[i]);
            if(x > w[i]) x = w[i];
            if(x < 0) x = 0;
            double y = d1 + x;
            ve.emplace_back(x, y);
        }
        sort(all(ve), [&](auto a, auto b) { return a.second < b.second; });
        for(auto &p : ve) {
            double x, y;
            tie(x, y) = p;
            auto it = s.lower_bound(make_pair(x, 0));
            while(it != s.end()) {
                double X, Y;
                tie(X, Y) = *it;
                if(Y < y - (X - x) + EPS) it = s.erase(it);
                else break;
            }
            while(it != s.begin()) {
                double X, Y;
                tie(X, Y) = *prev(it);
                if(Y < y - (x - X) + EPS) it = s.erase(prev(it));
                else break;
            }
            s.emplace(x, y);
        }
        val = min(val, d1max);
        val = min(val, d2max);
        for(auto it = s.begin(); it != s.end(); it++) {
            val = min(val, it->second);
            if(next(it) != s.end()) {
                double x, y, X, Y;
                tie(x, y) = *it;
                tie(X, Y) = *next(it);
                double xx = 0.5 * (y - Y + X + x);
                if(xx < x) xx = x;
                if(xx > X) xx = X;
                val = min(val, max(y - (xx - x), Y - (X - xx)));
            }
        }
        if(val < ans) ans = val;
    }
    cout << fixed << setprecision(10);
    cout << ans << '\n';
}