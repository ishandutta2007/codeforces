#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    vector <int> stk;
    int64_t sum = 0;
    int64_t add = 0;
    for (int mex = 0, ptr = 1 ; mex <= n ; ++ mex) {
        if (mex > 0 && stk.empty()) {
            cout << "-1 ";
            continue;
        } else if (mex > 0) {
            int need = mex - 1;
            add += need - stk.back();
            sum -= stk.back();
            stk.pop_back();
        }

        int64_t ans = add;
        while (ptr <= n && a[ptr] == mex) {
            stk.push_back(a[ptr]);
            sum += a[ptr];
            ptr += 1;
            ans += 1;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}