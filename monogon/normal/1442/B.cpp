
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

const int N = 2e5 + 5, M = 998244353;
int nxt[N], prv[N], a[N], b[N];
bool bad[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n, k;
        cin >> n >> k;
        rep(i, 1, n + 1) {
            cin >> a[i];
        }
        fill(nxt + 1, nxt + n + 1, -1);
        fill(prv + 1, prv + n + 1, -1);
        fill(bad + 1, bad + n + 1, false);
        rep(i, 2, n + 1) {
            nxt[a[i - 1]] = a[i];
            prv[a[i]] = a[i - 1];
        }
        rep(i, 1, k + 1) {
            cin >> b[i];
            bad[b[i]] = true;
        }
        ll ans = 1;
        rep(i, 1, k + 1) {
            int val = b[i];
            int cnt = 0;
            if(nxt[val] != -1 && !bad[nxt[val]]) cnt++;
            if(prv[val] != -1 && !bad[prv[val]]) cnt++;
            if(nxt[val] != -1) prv[nxt[val]] = prv[val];
            if(prv[val] != -1) nxt[prv[val]] = nxt[val];
            ans = (ans * cnt) % M;
        }
        ans = (ans % M + M) % M;
        cout << ans << '\n';
    }
}