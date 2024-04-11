#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
bool has[nax];
int cnt[nax];
int lazy[nax];
int64_t sum_cnt[nax];
int cnt_in_block[nax];
int64_t sum_ans[nax];
int q, d;
int64_t C2(int64_t x) {
    return x * (x - 1);
}

int bit[nax];
void update(int idx, int val) {
    ++ idx;
    for (; idx < nax ; idx += idx & -idx)
        bit[idx] += val;
}
int get(int idx) {
    ++ idx;
    idx = min(idx, nax - 1);
    int res = 0;
    for ( ; idx > 0 ; idx -= idx & -idx) res += bit[idx];
    return res;
}

#define C 300
void good(const vector <int> &a) {
    vector <int64_t> return_ans;
    int64_t ans = 0;
    for (const auto & x : a) {
        int lb = max(0, x - d);
        lb = (lb / C) * C;
        int real_lb = max(0, x - d);
        int add = has[x] ? -1 : 1;
      /*  auto get_ans = [&]() -> int64_t {
            int64_t ans = 0;
            for (int j = 0 ; j < nax ; j += C) {
                ans += sum_ans[j];
            }
            return ans;
        };**/
        for (int j = lb ; j <= x ; j += C) {
            if (j <= real_lb || j + C > x) {
                for (int k = max(real_lb, j) ; k < min(x + 1, j + C) ; ++ k) {
                    if (has[k]) {
                        ans -= sum_ans[j];
                        sum_ans[j] -= C2(cnt[k] + lazy[j]);
                        sum_ans[j] += C2(cnt[k] + lazy[j] + add);
                        sum_cnt[j] += add;
                        cnt[k] += add;
                        ans += sum_ans[j];

                    }
                }
                continue;
            }
            ans -= sum_ans[j];
            if (add > 0) sum_ans[j] += 2 * add * sum_cnt[j];
            if (add < 0) sum_ans[j] -= 2 * (sum_cnt[j] - cnt_in_block[j]);
            sum_cnt[j] += add * cnt_in_block[j];
            lazy[j] += add;
            ans += sum_ans[j];
        }


        int bl_x = x / C * C;
        ans -= sum_ans[bl_x];
        if (has[x]) {
            int real_cnt = cnt[x] + lazy[bl_x];
            sum_ans[bl_x] -= C2(real_cnt);
            sum_cnt[bl_x] -= real_cnt;
            cnt_in_block[bl_x] -= 1;
        } else {
            int real_cnt = get(x + d) - get(x - 1);
            cnt[x] = real_cnt - lazy[bl_x];
            sum_ans[bl_x] += C2(real_cnt);
            sum_cnt[bl_x] += real_cnt;
            cnt_in_block[bl_x] += 1;
        }
        ans += sum_ans[bl_x];
        update(x, add);
        has[x] ^= 1;
       // int64_t ans = get_ans();
        cout << ans / 2 << '\n';

    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> q >> d;

    vector <int> a(q);

    for (int &j : a) {
        cin >> j;
         j -= 1;
    }
    /// clean submission
    good(a);
}