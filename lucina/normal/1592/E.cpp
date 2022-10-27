#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
const int K = 22;
int n;
int a[nax];
int b[nax];
int large[nax];
int sum_large[nax];
int sum_b[nax];
int solve(int k) {

    for (int i = 1 ; i <= n ; ++ i) {
        b[i] = a[i] & (((1 << (k + 1)) - 1));
        large[i] = a[i] ^ b[i];
        sum_large[i] = large[i] ^ sum_large[i - 1];
    }

    vector <pair <int, int>> cc;
    int res = 0;
    for (int i = 1 ; i <= n ;) {
        if (!(b[i] >> k & 1)) {
            ++ i;
            continue;
        }
        int r = i;
        cc.clear();
        cc.emplace_back(sum_large[r - 1], r - 1);
        while (r <= n && (b[r] >> k & 1)) {
            cc.emplace_back(sum_large[r], r);
            ++ r;
        }
        auto &c = cc;
        sort(c.begin(), c.end());
        for (int j = 0 ; j < c.size();) {
            int jj = j;
            int min_v[2], max_v[2];
            memset(min_v, -1, sizeof(min_v));
            memset(max_v, -1, sizeof(max_v));
            while (jj < c.size() && c[jj].first == c[j].first) {
                int idx = c[jj].second;
                max_v[idx % 2] = max(max_v[idx % 2], idx);
                if (min_v[idx % 2] == -1) min_v[idx % 2] = idx;
                ++ jj;
            }
            for (int x = 0 ; x < 2 ; ++ x) {
                if (min_v[x] != -1 && max_v[x] != -1)
                res = max(res, max_v[x] - min_v[x]);
            }
            j = jj;
        }
        i = r;
    }
    return res;

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int k = 0 ; k <= K ; ++ k) {
        ans = max(ans, solve(k));
    }
    cout << ans << '\n';
}
/*
    Well, such a long time from last div.2 round
*/