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
const int N = 1e5 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int t, n;
char a[N], b[N];
vector<int> p[26];
struct fenw {
    int t[N];
    void clear() {
        for(int i = 0; i <= n; i++) t[i] = 0;
        return;
    }
    void add(int x, int v) {
        for(int i = x; i <= n; i += i & (-i)) t[i] += v;
        return;
    }
    int sum(int x) {
        int res = 0;
        for(int i = x; i > 0; i -= i & (-i)) res += t[i];
        return res;
    }
}cnt;
void solve() {
    cin >> n >> (a + 1) >> (b + 1);
    cnt.clear();
    for(int i = 1; i <= n; i++) cnt.add(i, 1);
    for(int i = 0; i < 26; i++) p[i].clear();
    for(int i = n; i >= 1; i--) {
        p[a[i] - 'a'].push_back(i);
    }
    ll ans = oo, sum = 0;
    for(int i = 1; i <= n; i++) {
        int c = b[i] - 'a';
        for(int j = 0; j < c; j++) {
            if(!p[j].empty()) {
                ans = min(ans, sum + cnt.sum(p[j].back()) - 1);
            }
        }
        if(p[c].empty()) break;
        sum += cnt.sum(p[c].back()) - 1;
        cnt.add(p[c].back(), -1), p[c].pop_back();
    }
    if(ans >= oo) ans = -1;
    cout << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}