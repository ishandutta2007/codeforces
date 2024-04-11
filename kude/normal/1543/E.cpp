#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VVI to(1 << n);
        rep(i, n * (1 << n - 1)) {
            int a, b;
            cin >> a >> b;
            to[a].push_back(b);
            to[b].push_back(a);
        }
        queue<int> q;
        VI dist(1 << n, -1);
        VI A(1 << n);
        dist[0] = 0;
        assert(to[0].size() == n);
        rep(i, n) {
            int v = to[0][i];
            dist[v] = 1;
            A[v] = 1 << i;
            q.push(v);
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v: to[u]) {
                if (dist[v] == -1) {
                    A[v] = A[u];
                    dist[v] = dist[u] + 1;
                    q.push(v);
                } else if (dist[v] == dist[u] + 1) {
                    A[v] |= A[u];
                }
            }
        }
        VI P(1 << n);
        rep(i, 1 << n) {
            P[A[i]] = i;
        }
        rep(i, 1 << n) cout << P[i] << " \n"[i + 1 == (1 << n)];
        if (n == 1) {
            cout << 0 << ' ' << 0 << '\n';
        } else if (n == 2) {
            VI col(4);
            rep(i, 2) {
                col[P[i]] = 0;
                col[P[i+2]] = 1;
            }
            rep(i, 4) cout << col[i] << " \n"[i + 1 == 4];
        } else if (n / (n & -n) == 1) {
            VI col(1 << n);
            rep(i, 1 << n) {
                int c = 0;
                rep(k, n) c ^= k * (i >> k & 1);
                c %= n;
                col[P[i]] = c;
            }
            rep(i, 1 << n) cout << col[i] << " \n"[i + 1 == (1 << n)];
        } else cout << -1 << '\n';
    }
}