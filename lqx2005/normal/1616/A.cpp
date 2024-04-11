#include <bits/stdc++.h>
#define pii pair<int, string>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 100 + 10;
int t, n;
map<int, int> cnt;
void solve() {
    cnt.clear();
    cin >> n;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        cnt[abs(x)]++;
    }
    int ans = 0;
    for(auto num : cnt) {
        if(num.x == 0) ans++;
        else {
            if(num.y == 1) ans++;
            else ans += 2;
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    int t;
    for(cin >> t; t--; solve());
    return 0;
}