#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int COEF = (int)1e6 * 2;
int n;
const int maxN = 31;
ld x[maxN];
int pts[maxN];
const int maxK = 228;
int inv[maxK];
vector<int> do_shift(vector<int>& poly) {
    // F(x) -> F(x - 1)
    vector<int> z(poly.size());
    for (int r = poly.size() - 1; r >= 0; r--) {
        int SZ = poly.size() - 1 - r;
        for (int x = SZ - 1; x >= 0; x--) {
            z[x + 1] = sum(z[x + 1], z[x]);
            z[x] = sub(0, z[x]);
        }
        z[0] = sum(z[0], poly[r]);
    }
    return z;
}
int main() {
  //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < maxK; i++) inv[i] = pw(i, mod - 2);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pts[i] = round(x[i] * COEF);
    }
    vector<int> z;
    for (int i = 0; i <= n; i++) {
        for (int sb = -n; sb <= n; sb++) {
            int t = pts[i] + COEF * sb;
            if (t >= 0 && t <= COEF * n) {
                z.emplace_back(t);
            }
        }
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    for (int& v : z) assert(v % 2 == 0);
    assert(z.back() == n * COEF);
    assert(z[0] == 0);
    vector<vector<int>> polys(z.size(), vector<int>(1, 1));
    polys[0][0] = 0;
    const int INF = 1e8;
    for (int i = 1; i <= n; i++) {
        vector<vector<int>> npolys(z.size(), vector<int>(1, 0));
        vector<pair<int,int>> events;
        vector<vector<int>> mem(z.size());
        for (int c = 1; c < z.size(); c++) {
            events.emplace_back((z[c] + z[c - 1]) / 2, c);
        }
        //open
        for (int c = 0; c + 1 < z.size(); c++) {
            events.emplace_back(z[c], INF + c);
            if (z[c] + COEF <= n * COEF) {
                events.emplace_back(z[c] + COEF, 3 * INF + c);
            }
        }
        //full
        for (int c = 1; c < z.size(); c++) {
            events.emplace_back(z[c], 2 * INF + c);
            if (z[c] + COEF <= n * COEF) {
                events.emplace_back(z[c] + COEF, 4 * INF + c);
            }
        }
        sort(events.begin(), events.end());
        vector<int> cur_poly(n + 3);
        for (auto& it : events) {
            int tp = it.second;
          //  cout << it.first << " " << tp << endl;
           // cout << " BEF " << endl;
            //for (int& v : cur_poly) cout << v << " ";
            //cout << endl;
            if (tp < INF) {
                npolys[tp] = cur_poly;
                while (!npolys[tp].empty() && npolys[tp].back() == 0) npolys[tp].pop_back();
                continue;
            }
            else if (tp < 2 * INF) {
                //I just open it
                tp -= INF;
                vector<int> inter_poly(polys[tp + 1].size() + 1);
                int alpha_val = 0;
                for (int t = 0; t < polys[tp + 1].size(); t++) {
                    inter_poly[t + 1] = mult(polys[tp + 1][t], inv[t + 1]);
                }
                int cur_pt = mult(z[tp], pw(COEF, mod - 2));
                for (int r = inter_poly.size() - 1; r >= 0; r--) {
                    alpha_val = sum(inter_poly[r], mult(cur_pt, alpha_val));
                }
                inter_poly[0] = sub(inter_poly[0], alpha_val);
                mem[tp + 1] = inter_poly;
                assert(inter_poly.size() <= cur_poly.size());
                for (int x = 0; x < inter_poly.size(); x++) {
                    cur_poly[x] = sum(cur_poly[x], inter_poly[x]);
                }
            }
            else if (tp < 3 * INF) {
                tp -= 2 * INF;
                auto& inter_poly = mem[tp];
                int alpha_val = 0;
                int cur_pt = mult(z[tp], pw(COEF, mod - 2));
                for (int r = inter_poly.size() - 1; r >= 0; r--) {
                    alpha_val = sum(inter_poly[r], mult(cur_pt, alpha_val));
                }
                for (int x = 0; x < inter_poly.size(); x++) {
                    cur_poly[x] = sub(cur_poly[x], inter_poly[x]);
                }
                mem[tp].resize(1);
                mem[tp][0] = alpha_val;
                cur_poly[0] = sum(cur_poly[0], alpha_val);
            }
            else if (tp < 4 * INF) {
                tp -= 3 * INF;
                cur_poly[0] = sub(cur_poly[0], mem[tp + 1][0]);
                int cur_pt = mult(z[tp + 1], pw(COEF, mod - 2));
                vector<int> inter_poly(polys[tp + 1].size() + 1);
                for (int t = 0; t < polys[tp + 1].size(); t++) {
                    inter_poly[t + 1] = mult(polys[tp + 1][t], inv[t + 1]);
                }
                int alpha_val = 0;
                for (int r = inter_poly.size() - 1; r >= 0; r--) {
                    alpha_val = sum(inter_poly[r], mult(alpha_val, cur_pt));
                }
                //inter_poly[0] = sub(inter_poly[0], alpha_val);
                for (int& v : inter_poly) v = sub(0, v);
                inter_poly = do_shift(inter_poly);
                /*int new_alpha_val = 0;
                int new_pt = sum(cur_pt, 1);
                for (int r = inter_poly.size() - 1; r >= 0; r--) {
                    new_alpha_val = sum(inter_poly[r], mult(new_alpha_val, new_pt));
                }
                assert(sum(new_alpha_val, alpha_val) == 0);
                cout << " HI " << new_alpha_val << " " << alpha_val << endl;*/
                inter_poly[0] = sum(inter_poly[0], alpha_val);
                mem[tp + 1] = inter_poly;
                for (int x = 0; x < inter_poly.size(); x++) {
                    cur_poly[x] = sum(cur_poly[x], inter_poly[x]);
                }
            }
            else {
                tp -= 4 * INF;
                auto& inter_poly = mem[tp];
                for (int x = 0; x < inter_poly.size(); x++) {
                    cur_poly[x] = sub(cur_poly[x], inter_poly[x]);
                }
            }
           // cout << " AFT " << endl;
            //for (int v : cur_poly) cout << v << " ";
            //cout << endl;
        }
        polys = npolys;
        int pos = lower_bound(z.begin(), z.end(), pts[i]) - z.begin();
        int calc_val = 0;
        int cur_pt = mult(pts[i], pw(COEF, mod - 2));
        for (int c = polys[pos].size() - 1; c >= 0; c--) {
            calc_val = sum(polys[pos][c], mult(cur_pt, calc_val));
        }
        for (int t = pos + 1; t < z.size(); t++) {
            polys[t].resize(1);
            polys[t][0] = calc_val;
        }
        //cout << " AFTER " << i << endl;
       // for (auto& it : polys) {
        //    for (int v : it) cout << v << " ";
         //   cout << endl;
       // }
        //cout << "-----------" << endl;
    }
    int ans = 0;
    int cur_pt = n;
    for (int x = polys.back().size() - 1; x >= 0; x--) {
        ans = sum(polys.back()[x], mult(cur_pt, ans));
    }
    cout << ans;
}