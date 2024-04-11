
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// key (length, index)
// check that index actually has this length
// if so, split it, update lengths

const int N = 2e5 + 5;
int t, n, a[N], l[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        fill(a + 1, a + n + 1, 0);
        fill(l + 1, l + n + 1, 0);
        priority_queue<pii> Q;
        l[1] = n;
        Q.emplace(n, -1);
        int it = 0;
        while(!Q.empty()) {
            auto p = Q.top(); Q.pop();
            int len = p.fi;
            int idx = -p.se;
            if(a[idx] != 0 || l[idx] != len) continue;
            int r = idx + len - 1;
            int m = (idx + r) / 2;
            if((r - idx + 1) % 2 == 0) m = (idx + r - 1) / 2;
            if(a[m] == 0) {
                a[m] = ++it;
                Q.emplace(l[idx] = m - idx, -idx);
                Q.emplace(l[m + 1] = idx + len - (m + 1), -(m + 1));
            }
        }
        rep(i, 1, n + 1) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}