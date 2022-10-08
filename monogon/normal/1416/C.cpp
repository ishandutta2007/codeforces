
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

const int N = 3e5 + 5;
int n, a[N];
ll inv01[31], inv10[31];

void solve(int l, int r, int bit) {
    if(l == r) return;
    ll cnt0 = 0, cnt1 = 0;
    rep(i, l, r) {
        if(((a[i] >> bit) & 1) == 0) {
            inv10[bit] += cnt1;
            cnt0++;
        }else {
            inv01[bit] += cnt0;
            cnt1++;
        }
    }
    int m = stable_partition(a + l, a + r, [&](int x) {
        return ((x >> bit) & 1) == 0;
    }) - a;
    if(bit > 0) {
        solve(l, m, bit - 1);
        solve(m, r, bit - 1);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    solve(0, n, 30);
    ll x = 0, ans = 0;
    rep(i, 0, 30) {
        if(inv01[i] < inv10[i]) {
            x ^= (1LL << i);
        }
        ans += min(inv01[i], inv10[i]);
    }
    cout << ans << ' ' << x << '\n';
}