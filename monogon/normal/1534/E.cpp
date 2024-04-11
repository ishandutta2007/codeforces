
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

// vi ans = {-1, 2, 1, 7, 5, 6};

int query(vi &q) {
    cout << "? ";
    int a = 0;
    for(int x : q) {
        cout << x << ' ';
        // a ^= ans[x];
    }
    cout << endl;
    int ans = a;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if(n % 2 == 1 && k % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    // number of ones
    vector<bool> vis(n + 1, false);
    vi par(n + 1);
    queue<int> Q;
    Q.push(0);
    vis[0] = true;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        rep(f, 0, k + 1) {
            if(f <= x && k - f <= n - x) {
                int xx = x - f + (k - f);
                if(!vis[xx]) {
                    vis[xx] = true;
                    Q.push(xx);
                    par[xx] = f;
                }
            }
        }
    }
    if(!vis[n]) {
        cout << -1 << endl;
        return 0;
    }
    int x = n;
    ll ans = 0;
    vi o, z;
    rep(i, 1, n + 1) o.push_back(i);
    while(x != 0) {
        int f = k - par[x];
        vi q;
        rep(i, 0, f) {
            q.push_back(o.back());
            o.pop_back();
        }
        rep(i, 0, k - f) {
            q.push_back(z.back());
            z.pop_back();
        }
        z.insert(z.end(), q.begin(), q.begin() + f);
        o.insert(o.end(), q.begin() + f, q.end());
        ans ^= query(q);
        x = sz(o);
    }
    cout << "! " << ans << endl;
}