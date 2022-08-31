#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;

#ifndef BZ
const int MAXN = 1000003;
#else
const int MAXN = 10001;
#endif

vector<int> dv[MAXN];

bool m2[MAXN];

int ans = MAXN;
int a[MAXN];


vector<pair<int,int>> g(int x) {
    vector<pair<int,int>> ans;

    for (int p : dv[x]) {
        int l = max(p, x - p) + 1;
        if (l <= x) {
            ans.emplace_back(l, x);
        }
    }

    return ans;
}

int s[MAXN];
int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i < MAXN; ++i) {
        if (dv[i].empty()) {
            for (int j = i + i; j < MAXN; j += i) {
                dv[j].push_back(i);
            }
        }
    }

    auto val = g(n);
    for (auto p : val) {
        s[p.first]++;
        s[p.second + 1]--;
    }
    
    for (int i = 1; i < MAXN; ++i) {
        s[i] += s[i - 1];
        if (s[i]) {
            for (auto p : g(i)) {
                ans = min(ans, p.first);
            }
        }
    }

    cout << ans << "\n";
}