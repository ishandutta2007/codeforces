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
        vector<P> ans;
        auto cmp = [&](int i, int j) {
            return a[i] < a[j];
        };
        priority_queue<int, VI, decltype(cmp)> q(cmp);
        rep(i, n) if (a[i]) q.push(i);
        while(q.size() >= 2) {
            int i = q.top(); q.pop();
            int j = q.top(); q.pop();
            ans.emplace_back(i, j);
            a[i]--, a[j]--;
            for(int k: {i, j}) if (a[k]) q.push(k);
        }
        int sz = ans.size();
        cout << sz << '\n';
        for(auto [i, j]: ans) {
            cout << i + 1 << ' ' << j + 1 << '\n';
        }
    }
}