#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int n;
    cin >> n;
    set<ll> s{0};
    int ans = 0;
    ll acc = 0;
    while(n--) {
        ll a;
        cin >> a;
        acc += a;
        if (s.count(acc) > 0) {
            ans += 1;
            acc = a;
            s = set<ll>{0, a};
        } else {
            s.insert(acc);
        }
    }
    cout << ans << endl;
}