#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N], nxt[N];
pair <int, int> p[N];
map <int, int> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        b[0] = 0;
        p[0] = make_pair(b[0], 0);
        for(int i = 0; i < n; i++) {
            b[i + 1] = b[i] ^ a[i];
            p[i + 1] = make_pair(b[i + 1], i + 1);
        }
        sort(p, p + n + 1);
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            if (i < n && p[i + 1].first == p[i].first) nxt[p[i].second] = p[i + 1].second;
            else nxt[p[i].second] = -1;
        }
        q.clear();
        for(int i = 0; i <= n; i++) {
            if (q.count(i)) {
                q.clear();
                q[nxt[i]] = 1;
            }
            else {
                ans++;
                q[nxt[i]] = 1;
            }
        }
        cout << ans - 1 << endl;
    }
}