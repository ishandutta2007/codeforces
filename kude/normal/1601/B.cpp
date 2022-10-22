#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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
    int n;
    cin >> n;
    n++;
    VI a(n), b(n);
    rep(i, n - 1) cin >> a[i + 1];
    rep(i, n - 1) cin >> b[i + 1];
    set<int, greater<int>> not_added;
    rep(i, n) not_added.insert(i);
    vector<int> pre(n, -1);
    vector<char> jumped(n);
    queue<int> q;
    auto push = [&](int u, int from) {
        // assert(pre[u] == -1);
        not_added.erase(u);
        pre[u] = from;
        q.push(u);
    };
    push(n - 1, -1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        int nu = u + b[u];
        if (jumped[nu]) continue;
        jumped[nu] = true;
        for(
            auto it = not_added.lower_bound(nu);
            it != not_added.end() && nu - *it <= a[nu];
            )
        {
            pre[*it] = u;
            q.push(*it);
            it = not_added.erase(it);
        }
    }
    if (pre[0] == -1) {
        cout << -1 << endl;
    } else {
        VI ans;
        int v = 0;
        while(pre[v] != -1) {
            ans.push_back(v);
            v = pre[v];
        }
        reverse(all(ans));
        int sz = ans.size();
        cout << sz << endl;
        rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
    }
    return 0;
}