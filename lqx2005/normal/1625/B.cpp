#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define vi vector<int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1.5e5 + 10;
int n, a[N];
vector<int> pos[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], pos[a[i]].push_back(i);
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        sort(pos[a[i]].begin(), pos[a[i]].end());
        for(int j = 1; j < sz(pos[a[i]]); j++) {
            ans = max(ans, pos[a[i]][j - 1] + n - pos[a[i]][j]);
        }
        pos[a[i]].clear();
    }
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