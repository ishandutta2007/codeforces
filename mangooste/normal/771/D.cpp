#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename T>
inline bool setmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    ar<vec<int>, 3> poses;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int type;
        if (c == 'V') {
            type = 0;
        } else if (c == 'K') {
            type = 1;
        } else {
            type = 2;
        }
        poses[type].push_back(i);
    }
    vec<vec<vec<ar<int, 3>>>> dp(len(poses[0]) + 1, vec<vec<ar<int, 3>>>(len(poses[1]) + 1, vec<ar<int, 3>>(len(poses[2]) + 1, {INF, INF, INF})));
    for (int i = 0; i < 3; i++) {
        dp[0][0][0][i] = 0;
    }
    ar<int, 3> cur_i;
    for (cur_i[0] = 0; cur_i[0] <= len(poses[0]); cur_i[0]++) {
        for (cur_i[1] = 0; cur_i[1] <= len(poses[1]); cur_i[1]++) {
            for (cur_i[2] = 0; cur_i[2] <= len(poses[2]); cur_i[2]++) {
                for (int take = 0; take < 3; take++) {
                    if (cur_i[take] == 0) continue;
                    ar<int, 3> ncur = cur_i;
                    ncur[take]--;
                    for (int prev = 0; prev < 3; prev++) {
                        if (prev == 0 && take == 1) continue;
                        auto didnt_get = [&](vec<int> &poses, int i, int pos) {
                            return max<int>(0, upper_bound(all(poses), pos) - poses.begin() - 1 - (i - 1));
                        };
                        int id = 0;
                        for (int i = 0; i < 3; i++) {
                            if (i == take) continue;
                            id += didnt_get(poses[i], cur_i[i], poses[take][cur_i[take] - 1]);
                        }
                        setmin(dp[cur_i[0]][cur_i[1]][cur_i[2]][take], dp[ncur[0]][ncur[1]][ncur[2]][prev] + id);
                    }
                }
            }
        }
    }
    cout << *min_element(all(dp.back().back().back())) << '\n';
}