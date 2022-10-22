#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef double db;
const int N = 500 + 10;
int n, a[N];
map<int, int> cnt;
void solve() {
    cnt.clear();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i], cnt[a[i]]++;
    }
    for(int i = 1; i <= n; i++) if(cnt[a[i]] & 1) return cout << -1 << endl, void();
    vector<int> p, c, t;
    int m = n, two = 0;
    int delta = 0;
    while(m) {
        int x = -1;
        for(int i = 1; i < m; i++) {
            if(a[i] == a[m]) {
                x = i;
                break;
            }
        }
        delta += x;
        for(int i = 1; i <= x; i++) {
            p.push_back(delta), c.push_back(a[i]);
            delta++;
        }
        reverse(a + 1, a + x + 1);
        t.push_back(x * 2);
        delta += m - 1;
        t.push_back((m - 1) * 2);
        for(int i = 1; i <= m - 1; i++) {
            p.push_back(delta), c.push_back(a[i]);
            delta++;
        }
        reverse(a + 1, a + m);
        m -= 2, two++;
    }
    cout << sz(p) << endl;
    for(int i = 0; i < sz(p); i++) cout << p[i] <<" " << c[i] << endl;
    cout << sz(t) + two << endl;
    for(int i = 0; i < sz(t); i++) cout << t[i] <<" ";
    while(two--) cout << 2 <<" ";
    cout << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}