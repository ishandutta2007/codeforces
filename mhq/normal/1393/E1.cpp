#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int sumMod(int a, int b, int m) {
    a += b;
    if (a >= m) {
        a -= m;
    }
    return a;
}

const int LOG = 20;
const int INF = (int)1e9;

class suffarray {
public:
    vector<int> lg;
    vector<int> p;
    vector<int> lcp;
    vector<int> up[LOG];
    vector<int> op;
    suffarray(vector<int>& p, vector<int>& lcp) : lg(p.size()+1), p(p), lcp(lcp), op(p.size()) {
        for (int i = 2; i < (int)p.size(); ++i) {
            lg[i] = lg[i >> 1] + 1;
        }
        for (int j = 0; j < LOG; j++) {
            up[j].resize(p.size());
        }
        for (int i = 0; i < (int)p.size(); i++) {
            op[p[i]] = i;
            up[0][i] = lcp[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) - 1 < (int)p.size(); i++) {
                up[j][i] = min(up[j - 1][i], up[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int getlcp(int i, int j) {
        if (i == j) {
            return INF;
        }
        i = op[i];
        j = op[j];
        if (i > j) {
            swap(i, j);
        }
        j--;
        int k = lg[j - i + 1];
        return min(up[k][i], up[k][j - (1 << k) + 1]);
    }
};

suffarray build(string s) {
    string t = s + " ";
    int k = t.size();
    vector<int> c(k);
    vector<int> cn(k);
    vector<int> p(k);
    vector<int> op(k);
    vector<int> pn(k);
    vector<int> lcp(k);
    vector<int> f(k + 1);
    vector<pair<int, int>> d(k);
    for (int i = 0; i < k; i++) {
        d[i] = make_pair(t[i], i);
    }
    sort(d.begin(), d.end());
    int cls = 0;
    for (int i = 0; i < k; i++) {
        if (i == 0 || d[i].first != d[i - 1].first) {
            cls++;
        }
        c[d[i].second] = cls;
        p[i] = d[i].second;
    }
    for (int h = 0; (1 << h) < k; h++) {
        for (int i = 0; i <= cls; i++) {
            f[i] = 0;
        }
        for (int i = 0; i < k; i++) {
            int x = p[i] - (1 << h);
            if (x < 0) {
                x += k;
            }
            pn[i] = x;
            f[c[x]]++;
        }
        for (int i = 1; i <= cls; i++) {
            f[i] += f[i - 1];
        }
        for (int i = k - 1; i >= 0; i--) {
            p[f[c[pn[i]]] - 1] = pn[i];
            f[c[pn[i]]]--;
        }
        cls = 1;
        cn[p[0]] = 1;
        for (int i = 0; i + 1 < k; i++) {
            auto m1 = make_pair(c[p[i]], c[sumMod(p[i], (1 << h), k)]);
            auto m2 = make_pair(c[p[i + 1]], c[sumMod(p[i + 1], (1 << h), k)]);
            if (m1 != m2) {
                cls++;
            }
            cn[p[i + 1]] = cls;
        }
        for (int i = 0; i < k; i++) {
            c[i] = cn[i];
        }
    }

    for (int i = 0; i < k; i++) {
        op[p[i]] = i;
    }

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (cnt > 0) {
            cnt--;
        }
        if (op[i]== k - 1) {
            lcp[k - 1] = -1;
            cnt = 0;
        } else {
            int j = p[op[i] + 1];
            while (max(i + cnt, j + cnt) < k && t[i + cnt] == t[j + cnt]) {
                cnt++;
            }
            lcp[op[i]] = cnt;
        }
    }
    return suffarray{p, lcp};
}
const int maxN = 1e5 + 10;
int n;
string s[maxN];
int pos[maxN];
const int mod = (int)1e9 + 7;
vector < int > his_poses[maxN];
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    string tt;
    tt += 'z';
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        pos[i] = tt.size();
        tt += s[i];
    }
    tt += 'z';
    tt += 'z';
    tt += 'z';
    auto sp = build(tt);
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= (int)s[i].size(); j++) {
            all.emplace_back(i, j);
        }
    }
    sort(all.begin(), all.end(), [&](pair < int, int >& a, pair < int, int >& b) {
        int pos1 = pos[a.first];
        int pos2 = pos[b.first];
        int lcp1 = sp.getlcp(pos1, pos2);
        if (lcp1 < min(a.second, b.second)) {
            return tt[pos1 + lcp1] < tt[pos2 + lcp1];
        }

        int let1 = s[a.first].size() - (a.second != (s[a.first].size()));
        int let2 = s[b.first].size() - (b.second != (s[b.first].size()));
        let1 -= min(a.second, b.second);
        let2 -= min(a.second, b.second);
        if (let1 == 0 || let2 == 0) {
            if (let1 != let2) return let1 < let2;
            return pos1 < pos2;
        }
        if (a.second <= b.second) {
            int lcp2 = sp.getlcp(pos1 + a.second + 1, pos2 + a.second);
//            cout << lcp2 << " GGWP " << endl;
            int lft_len = min(b.second - a.second, min(let1, let2));
            if (lcp2 < lft_len) {
                return tt[pos1 + a.second + 1 + lcp2] < tt[pos2 + a.second + lcp2];
            }
            let1 -= lft_len;
            let2 -= lft_len;
        }
        else {
            int lft_len = min(a.second - b.second, min(let1, let2));
            int lcp2 = sp.getlcp(pos1 + b.second, pos2 + b.second + 1);
            if (lcp2 < lft_len) {
                return tt[pos1 + b.second + lcp2] < tt[pos2 + b.second + lcp2 + 1];
            }
            let1 -= lft_len;
            let2 -= lft_len;
        }
        if (let1 == 0 || let2 == 0) {
            if (let1 != let2) return let1 < let2;
            return pos1 < pos2;
        }
        int d = max(a.second, b.second);
        int lcp3 = sp.getlcp(pos1 + d + 1, pos2 + d + 1);
        if (lcp3 < min(let1, let2)) {
            return tt[pos1 + d + 1 + lcp3] < tt[pos2 + d + 1 + lcp3];
        }
        else {
            if (let1 != let2) return let1 < let2;
            return pos1 < pos2;
        }
    });
    for (int i = 0; i < all.size(); i++) {
        his_poses[all[i].first].emplace_back(i);
    }
    vector < vector < int > > dp(n + 1);
//    for (auto& it : all) {
//        cout << it.first << " " << it.second << " HI " << endl;
//    }
//    cout << "---------------" << endl;
    for (int i = 1; i <= n; i++) {
        dp[i].resize(s[i].size() + 1);
    }
    for (int& v : dp[1]) v = 1;
    for (int i = 1; i + 1 <= n; i++) {
        int cur_sum = 0;
        int cl = 0;
        int cr = 0;
        while (cl <= s[i].size() && cr <= s[i + 1].size()) {
            if (his_poses[i][cl] < his_poses[i + 1][cr]) {
                cur_sum = sum(cur_sum, dp[i][all[his_poses[i][cl]].second]);
                cl++;
            }
            else {
                dp[i + 1][all[his_poses[i + 1][cr]].second] = sum(dp[i + 1][all[his_poses[i + 1][cr]].second], cur_sum);
                cr++;
            }
        }
        while (cr <= s[i + 1].size()) {
            dp[i + 1][all[his_poses[i + 1][cr]].second] = sum(dp[i + 1][all[his_poses[i + 1][cr]].second], cur_sum);
            cr++;
        }
    }
    int ans = 0;
    for (int v : dp[n]) ans = sum(ans, v);
    cout << ans;
    return 0;
}