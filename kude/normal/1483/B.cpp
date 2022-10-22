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
        VI a(n);
        rep(i, n) cin >> a[i];
        VI nxt(n), pre(n);
        queue<P> q;
        rep(i, n) {
            int j = (i + 1) % n;
            nxt[i] = j;
            pre[j] = i;
            if (gcd(a[i], a[j]) == 1) {
                q.emplace(i, j);
            }
        }
        //rep(i, n) cout << pre[i] << ' ' << nxt[i] << endl;
        VI ans;
        VI dead(n);
        while(!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            //cout << i << ' ' << j << endl;
            if (dead[i] || dead[j]) continue;
            ans.push_back(j);
            dead[j] = true;
            if (i == j) break;
            int k = nxt[j];
            nxt[i] = k;
            pre[k] = i;
            if (gcd(a[i], a[k]) == 1) q.emplace(i, k);
        }
        int sz = ans.size();
        cout << sz;
        rep(i, sz) cout << ' ' << ans[i] + 1;
        cout << '\n';
    }
}