// desprado2
#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
 
const int N = 100005;
int n, m, w[N];
vector<pair<int, vector<int>>> t;
unordered_map<ull, vector<int>> ID;
ull Hvalue[N][33];
ull encode(const vector<int>& v){
    if (v.empty()) return 0;
    ull ret = 1;
    for (auto i : v) ret = ret * 114514 + i;
    return ret;
}
bool check(int i, int j){
    if (j > n) return true;
    int ans = 0;
    for (int mask = 1; mask < (1 << m); mask++){
        auto &v = ID[Hvalue[i][mask]];
        auto x = lower_bound(v.begin(), v.end(), i), y = upper_bound(v.begin(), v.end(), j) - 1;
        int cnt = y - x;
        int sign = (__builtin_popcount(mask) & 1 ? 1 : -1);
        ans += cnt * sign;
    }
    return ans < j - i;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    ID.reserve(n * 32);
    t.emplace_back(-1, vector<int>());
 
    for (int i = 1, tmp, cnt = 0; i <= n; i++){
        vector<int> vec(m);
        for (int j = 0; j < m; j++) cin >> vec[j];
        cin >> tmp;
        sort(vec.begin(), vec.end());
        int x = unique(vec.begin(), vec.end()) - vec.begin();
        if (x == m) t.emplace_back(tmp, vec), w[++cnt] = tmp;
    }
    n = t.size() - 1;
    sort(t.begin() + 1, t.end());
    sort(w + 1, w + n + 1);
 
    for (int i = 1; i <= n; i++){
        for (int mask = 1; mask < (1 << m); mask++){
            vector<int> tmp;
            for (int k = 0; k < m; k++)
                if (mask >> k & 1) tmp.push_back(t[i].second[k]);
            auto H = encode(tmp);
            Hvalue[i][mask] = H, ID[H].push_back(i);
        }
    }
    int ans = INT_MAX;
    int p = n;
    for (int i = 1; i <= n; i++){
		while (p > i && w[i] + w[p] >= ans) p--;
		if (p <= i) break;
		while (p > i && check(i, p)) ans = w[i] + w[p--];
    }
    if (ans > 2e9) cout << -1;
    else cout << ans;
}