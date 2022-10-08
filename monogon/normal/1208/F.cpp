
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

const int N = 1e6 + 5, LG = 21;
int n, a[N], cnt[1 << LG];

void dfs(int mask, int i) {
    if(cnt[mask] >= 2 || i == LG) return;
    cnt[mask]++;
    rep(j, i, LG) {
        if(((mask >> j) & 1) == 1) {
            dfs(mask - (1 << j), j + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(i <= n - 3) {
            int mask = 0;
            for(int l = 20; l >= 0; l--) {
                if(((a[i] >> l) & 1) == 0 && cnt[mask + (1 << l)] >= 2) {
                    mask += (1 << l);
                }
            }
            ans = max(ans, a[i] | mask);
        }
        dfs(a[i], 0);
    }
    cout << ans << '\n';
}