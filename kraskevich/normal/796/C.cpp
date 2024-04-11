#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 300 * 1000 + 10;
const ll INF = ll(1e18);

vector<int> g[N];
ll a[N];
int n;

void del(map<ll, int>& mp, ll x) {
    mp[x]--;
    if (mp[x] == 0)
        mp.erase(x);
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    map<ll, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < n - 1; i++) {
        int c, b;
        cin >> c >> b;
        --c;
        --b;
        g[c].push_back(b);
        g[b].push_back(c);
    }
    ll res = INF;
    for (int i = 0; i < n; i++) {
        ll cur = a[i];
        del(cnt, a[i]);
        for (int to : g[i]) {
            cur = max(cur, a[to] + 1);
            del(cnt, a[to]);
        }
        if (cnt.size()) {
            auto it = cnt.end();
            it--;
            cur = max(cur, it->first + 2);
        }
        cnt[a[i]]++;
        for (int to : g[i])
            cnt[a[to]]++;
        res = min(res, cur);
    }
    cout << res << endl;
}