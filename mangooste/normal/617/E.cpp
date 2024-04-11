#include <bits/stdc++.h>

using namespace std;

struct query {
    int L;
    int R;
    int num;

    query(int L = 0, int R = 0, int num = -1) :
        L(L), R(R), num(num)
    {}
};

const int MAXA = 2.1e6;
const int BLOCK = 500;

vector<int> cnt(MAXA, 0);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> b(n + 1, 0);
    for (int i = 0; i < n; i++)
        b[i + 1] = b[i] ^ a[i];
    vector<long long> ans(m);
    vector<query> qes(m);
    for (int i = 0; i < m; i++) {
        cin >> qes[i].L >> qes[i].R;
        qes[i].L--;
        qes[i].num = i;
    }
    sort(qes.begin(), qes.end(), [&](query a, query b) {
        a.L /= BLOCK;
        b.L /= BLOCK;
        return pair<int, int>{a.L, a.R} < pair<int, int>{b.L, b.R};
    });
    int cur_l = 0, cur_r = -1;
    long long cur_ans = 0;
    auto add_element = [&](int el) {
        int x = el ^ k;
        cur_ans += cnt[x];
        cnt[el]++;
    };
    auto delete_element = [&](int el) {
        cnt[el]--;
        int x = el ^ k;
        cur_ans -= cnt[x];
    };
    for (auto [L, R, num] : qes) {
        while (cur_r < R) {
            cur_r++;
            add_element(b[cur_r]);
        }
        while (cur_l > L){
            cur_l--;
            add_element(b[cur_l]);
        }
        while (cur_r > R) {
            delete_element(b[cur_r]);
            cur_r--;
        }
        while (cur_l < L) {
            delete_element(b[cur_l]);
            cur_l++;
        }
        ans[num] = cur_ans;
    }
    for (auto x : ans)
        cout << x << '\n';
}