
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

int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    int p0 = 0, p1 = 1;
    while(q--) {
        int ty;
        cin >> ty;
        if(ty == 1) {
            int x;
            cin >> x;
            p0 = (p0 + x) % n;
            p1 = (p1 + x) % n;
        }else {
            if(p0 < 0) p0 += n;
            if(p1 < 0) p1 += n;
            p0 ^= 1;
            p1 ^= 1;
        }
    }
    vi ans(n + 1);
    if(p0 < 0) p0 += n;
    if(p1 < 0) p1 += n;
    rep(i, 0, n / 2) {
        ans[p0 + 1] = 2 * i + 1;
        ans[p1 + 1] = 2 * i + 2;
        p0 += 2;
        p1 += 2;
        p0 %= n;
        p1 %= n;
    }
    rep(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}