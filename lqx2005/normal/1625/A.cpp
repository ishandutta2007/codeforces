#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define vi vector<int>
using namespace std;
typedef long long ll;
typedef double db;
int cnt[30][2];
void solve() {
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < l; i++) cnt[i][0] = cnt[i][1] = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < l; j++) cnt[j][x >> j & 1]++;
    }
    int ans = 0;
    for(int j = 0; j < l; j++) if(cnt[j][0] < cnt[j][1]) ans |= 1 << j;
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