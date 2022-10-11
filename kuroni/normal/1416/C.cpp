#include <bits/stdc++.h>
using namespace std;

const int N = 200005, LG = 30;

int n;
long long cnt[LG][2];

void solve(int b, vector<int>& ve) {
    if (ve.empty()) {
        return;
    }
    vector<int> bi[2];
    for (int v : ve) {
        int c = (v >> b & 1);
        bi[c].push_back(v);
        cnt[b][c] += bi[c ^ 1].size();
    }
    if (b >= 0) {
        solve(b - 1, bi[0]);
        solve(b - 1, bi[1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }
    solve(LG - 1, a);
    int ans = 0;
    long long inv = 0;
    for (int i = LG - 1; i >= 0; i--) {
        if (cnt[i][1] < cnt[i][0]) {
            ans ^= (1 << i);
        }
        inv += min(cnt[i][0], cnt[i][1]);
    }
    cout << inv << " " << ans << '\n';
}