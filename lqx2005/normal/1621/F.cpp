#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
int n, s[N];
int a, b, c;
void solve() {
    cin >> n >> a >> b >> c;
    for(int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        s[i] = x - '0';
    }
    vector<pair<int, int>> con;
    for(int i = 1, now = -1; i <= n; i++) {
        if(now != s[i]) {
            con.eb(1, now = s[i]);
        } else con.back().x++;
    }
    int p[2] = {0, 0}, r[2] = {0, 0};
    for(auto s : con) p[s.y] += s.x - 1, r[s.y] += s.x;
    vector<int> cons;
    for(int i = 1; i + 1 < sz(con); i++) if(con[i].y == 0) cons.push_back(con[i].x); 
    if(p[0] < p[1]) {
        ll ans = 0;
        ans += 1ll * p[0] * a;
        ans += 1ll * (p[0] + 1) * b;
        ans += 1ll * max(b - c, 0) * min(r[1] - p[0] - 1 - 1, r[0] - p[0]);
        cout << ans << endl;
    } else if(p[0] > p[1]) {
        ll ans = 0;
        ans += 1ll * p[1] * a;
        ans += 1ll * p[1] * b;
        sort(cons.begin(), cons.end());
        int cnt = 0, sum = 0;
        for(int x : cons) {
            if(sum + x - 1 <= p[1]) {
                sum += x - 1;
                cnt++;
            }
        }
		ans += 1ll * max(0, b - c) * cnt;
		ans += a;
        cout << ans << endl;
    } else {
        ll ans = 0;
        ans += 1ll * p[0] * (a + b);
        if(r[1] > p[1]) ans += 1ll * (r[1] - p[1] - 1) * max(0, b - c);
        cout << ans << endl;
    }
    return;
}
int main() {
    int t;
    for(cin >> t; t--; solve());
	return 0;
}