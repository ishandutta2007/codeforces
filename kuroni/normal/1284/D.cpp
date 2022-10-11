#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int n, s, t;
long long val[N], sa[N], sb[N];
vector<pair<int, int>> va, vb;
mt19937_64 mt(133769420);

void solve(vector<pair<int, int>> &ve, long long sum[N]) {
    long long suf = accumulate(val + 1, val + n + 1, 0LL);
    long long pre = 0;
    sort(ve.begin(), ve.end());
    for (pair<int, int> &v : ve) {
        int u = v.second;
        if (u < 0) {
            sum[-u] += pre;
            suf -= val[-u];
        } else {
            sum[u] += suf;
            pre += val[u];
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        val[i] = mt();
        cin >> s >> t;
        va.push_back({s, -i});
        va.push_back({t, i});
        cin >> s >> t;
        vb.push_back({s, -i});
        vb.push_back({t, i});
    }
    solve(va, sa);
    solve(vb, sb);
    for (int i = 1; i <= n; i++) {
        if (sa[i] != sb[i]) {
            return cout << "NO", 0;
        }
    }
    cout << "YES\n";
}