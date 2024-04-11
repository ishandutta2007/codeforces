
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n + 1), par(n + 1), jump(n + 1);
    const int K = 320;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    auto upd = [&](int i) {
        if(i + a[i] > n) {
            par[i] = i;
            jump[i] = 0;
        }else if((i + a[i]) / K != i / K) {
            par[i] = i + a[i];
            jump[i] = 1;
        }else {
            par[i] = par[i + a[i]];
            jump[i] = 1 + jump[i + a[i]];
        }
    };
    for(int i = n; i >= 1; i--) upd(i);
    while(m--) {
        int ty, i, x;
        cin >> ty >> i;
        if(ty == 0) {
            cin >> x;
            a[i] = x;
            for(int j = i; j / K == i / K && j >= 1; j--) {
                upd(j);
            }
        }else {
            int ans = 1;
            while(par[i] != i) {
                ans += jump[i];
                i = par[i];
            }
            cout << i << ' ' << ans << '\n';
        }
    }
}