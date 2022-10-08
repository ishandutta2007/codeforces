
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;


template<int m>
struct mod {
    long long x;
    mod() : x(0) {}
    mod(long long xx) : x(xx) {
        if(abs(x) >= m) x %= m;
        if(x < 0) x += m;
    }
    mod operator+(const mod &a) const {
        mod n;
        n.x = x + a.x;
        if(n.x >= m) n.x -= m;
        return n;
    }
    mod operator-(const mod &a) const {
        mod n;
        n.x = x - a.x;
        if(n.x < 0) n.x += m;
        return n;
    }
    mod operator*(const mod &a) const {
        return x * a.x;
    }
    mod operator+=(const mod &a) {
        x += a.x;
        if(x >= m) x -= m;
        return *this;
    }
    mod operator-=(const mod &a) {
        x -= a.x;
        if(x < 0) x += m;
        return *this;
    }
    mod operator*=(const mod &a) {
        x = (x * a.x) % m;
        return *this;
    }
    mod pow(long long b) const {
        mod ans = 1;
        mod a = *this;
        while(b > 0) {
            if(b & 1) ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }
    mod inv() const {
        return pow(m - 2);
    }
    mod operator/(const mod &a) const {
        return (*this) * a.inv();
    }
    mod operator/=(const mod &a) {
        return (*this) *= a.inv();
    }
    bool operator==(const mod &o) const {
        return x == o.x;
    }
    bool operator!=(const mod &o) const {
        return x != o.x;
    }
    long long operator()() const {
        return x;
    }
};

template<int m>
istream &operator>>(istream &is, mod<m> &n) {
    long long x;
    is >> x;
    n = x;
    return is;
}

const int M = 998244353;
using base = mod<M>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vi> dist(n + 1, vi(n + 1, INT_MAX));
    vector<bool> vis(n + 1, false);
    rep(s, 1, n + 1) {
        queue<int> Q;
        dist[s][s] = 0;
        fill(all(vis), false);
        vis[s] = true;
        Q.push(s);
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int y : g[x]) {
                if(!vis[y]) {
                    vis[y] = true;
                    dist[s][y] = 1 + dist[s][x];
                    Q.push(y);
                }
            }
        }
    }
    
    vector<vi> res(n + 1, vi(n + 1, 0));
    rep(x, 1, n + 1) {
        // for(int y : g[x]) {
        //     for(int z : g[x]) {
        //         if(z != y && dist[z][y] != 1) {
        //             bool flag = true;
        //             base ans = 1;
        //             rep(u, 1, n + 1) {
        //                 if(u == x || u == y || u == z) continue;
        //                 int m = 0;
        //                 if(dist[x][u] <= min(dist[z][u], dist[y][u]) && dist[z][u] == dist[x][u] + 1 && dist[y][u] == dist[x][u] + 1) {
        //                     for(int v : g[u]) {
        //                         if(dist[x][v] + 1 == dist[x][u]) m++;
        //                     }
        //                 }else if(dist[z][u] <= min(dist[x][u], dist[y][u]) && dist[x][u] == dist[z][u] + 1 && dist[y][u] == dist[z][u] + 2) {
        //                     for(int v : g[u]) {
        //                         if(dist[z][v] + 1 == dist[z][u]) m++;
        //                     }
        //                 }else if(dist[y][u] <= min(dist[x][u], dist[z][u]) && dist[x][u] == dist[y][u] + 1 && dist[z][u] == dist[y][u] + 2) {
        //                     for(int v : g[u]) {
        //                         if(dist[y][v] + 1 == dist[y][u]) m++;
        //                     }
        //                 }else {
        //                     flag = false;
        //                 }
        //                 ans *= m;
        //             }
        //             if(!flag) continue;
        //             res[y][z] = res[z][y] = ans();
        //         }
        //     }

        //     // check x, y
        //     bool flag = true;
        //     rep(z, 1, n + 1) {
        //         if(abs(dist[x][z] - dist[y][z]) != 1) flag = false;
        //     }
        //     if(!flag) continue;
        //     base ans = 1;
        //     rep(z, 1, n + 1) {
        //         if(z == x || z == y) continue;
        //         int m = 0;
        //         if(dist[x][z] < dist[y][z]) {
        //             for(int w : g[z]) {
        //                 if(dist[x][w] + 1 == dist[x][z]) {
        //                     m++;
        //                 }
        //             }
        //         }else {
        //             for(int w : g[z]) {
        //                 if(dist[y][w] + 1 == dist[y][z]) {
        //                     m++;
        //                 }
        //             }
        //         }
        //         ans *= m;
        //     }
        //     res[x][y] = res[y][x] = ans();
        // }
        rep(y, 1, n + 1) {
            if(y != x) {
                base ans = 1;
                int cnt = 0;
                rep(z, 1, n + 1) {
                    if(z == x) continue;
                    int m = 0;
                    if(dist[z][x] + dist[z][y] == dist[x][y]) {
                        cnt++;
                        for(int w : g[z]) {
                            if(dist[x][w] + 1 == dist[x][z] && dist[y][z] + 1 == dist[y][w]) {
                                m++;
                            }
                        }
                    }else {
                        for(int w : g[z]) {
                            if(dist[x][w] + 1 == dist[x][z] && dist[y][w] + 1 == dist[y][z]) m++;
                        }
                    }
                    ans *= m;
                }
                if(cnt == dist[x][y]) {
                    res[x][y] = res[y][x] = ans();
                }
            }
        }

        // check x, x
        base ans = 1;
        rep(z, 1, n + 1) {
            if(z == x) continue;
            int m = 0;
            for(int w : g[z]) {
                if(dist[x][w] + 1 == dist[x][z]) m++;
            }
            ans *= m;
        }
        res[x][x] = ans();
    }
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}