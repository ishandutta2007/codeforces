#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;

typedef double db;
typedef long long i64;
const int N = 1e5 + 10;
int n, m, a[N], b[N];
map<int, int> cnt;
int calc(int d) {
    cnt.clear();
    int k = 1 << d;
    for(int i = 1; i <= n; i++) {
        cnt[(a[i] + k) % (k << 1)]++;
    }
    for(int i = 1; i <= m; i++) {
        cnt[b[i] % (k << 1)]++;
    }
    int ans = 0;
    for(pair<int, int> v : cnt) {
        ans = max(ans, v.second);
    }
    return ans;
}

int main() {
    int y;
    cin >> n >> y;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m >> y;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int ans = 2;
    for(int d = 0; d <= 29; d++) ans = max(ans, calc(d));
    cout << ans << endl;
    return 0;
}