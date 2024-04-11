#include <bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second

using namespace std;
typedef long long ll;


const int max_n = 200111;

int vis[max_n];

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
    }
    sort(v.begin(), v.end());
    int mn = 0;
    for (int a : v) {
        if (vis[a - 1] || vis[a] || vis[a + 1]) {
            continue;
        }
        ++mn;
        vis[a + 1] = 1;
    }
    int mx = 0;
    memset(vis, 0, sizeof(vis));
    for (int a : v) {
        bool placed = 0;
        for (int i = -1; i <= 1; ++i) {
            if (!vis[a + i]) {
                vis[a + i] = 1;
                ++mx;
                break;
            }
        }
    }
    cout << mn << ' ' << mx << endl;
    return 0;
}