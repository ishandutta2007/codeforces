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
        VI remained(n);
        VVI to(n);
        rep(i, n) {
            cin >> remained[i];
            rep(_, remained[i]) {
                int x;
                cin >> x;
                x--;
                to[x].push_back(i);
            }
        }
        set<int> ready;
        int ans = 0;
        rep(i, n) if (remained[i] == 0) {
            ready.insert(i);
        }
        while(ready.size()) {
            ans++;
            for(auto it = ready.begin(); it != ready.end(); it = ready.erase(it)) {
                int i = *it;
                for(int j: to[i]) if (--remained[j] == 0) ready.insert(j);
            }
        }
        bool ok = true;
        rep(i, n) if (remained[i]) ok = false;
        if (!ok) ans = -1;
        cout << ans << '\n';
    }
}