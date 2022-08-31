#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 15;
int dp[(1 << maxN) + 2][maxN + 2];
int actual[(1 << maxN) + 2][maxN + 2];
int n;
int a[maxN];
int nxt[maxN + 2];
int SZ_TREE = 0;
const int maxP = 1e7 + 10;
int prv_node[maxP];
int his_mask[maxP];

void solve() {
//    n = rand() % 15 + 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
//        a[i] = rand() % 1000000 + 1;
//        cout << a[i] << " ";
    }
//    cout << endl;
    vector<pair<int, int>> v;
    SZ_TREE = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int S = 0;
        for (int z = 0; z < n; z++) {
            if (mask & (1 << z)) S += a[z];
        }
        v.emplace_back(S, mask);
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int pos = 0; pos < n; pos++) {
            dp[mask][pos] = -1e9;
            actual[mask][pos] = -1;
        }
    }
    sort(v.begin(), v.end());
    int ptr = 0;
    while (ptr < v.size()) {
        int nptr = ptr;
        while (nptr < v.size() && v[nptr].first == v[ptr].first) nptr++;
        nptr--;
        vector<tuple<int, int, int, int>> updates;
        for (int x = ptr; x <= nptr; x++) {
            int mask = v[x].second;
            int sb = ((1 << n) - 1) ^ mask;
            int cur = sb;
            nxt[n] = -1;
            for (int z = n - 1; z >= 0; z--) {
                nxt[z] = nxt[z + 1];
                if (mask & (1 << z)) nxt[z] = z;
            }
            while (true) {
                if (cur == 0) {
                    if (dp[mask][nxt[0]] < 1) {
                        updates.emplace_back(mask, nxt[0], 1, -1);
                    }
                } else {
                    for (int pos = 0; pos < n; pos++) {
                        if (nxt[pos] == -1) continue;
                        if (dp[mask | cur][nxt[pos]] < dp[cur][pos] + 1 && actual[cur][pos] != -1) {
                            updates.emplace_back(mask | cur, nxt[pos], dp[cur][pos] + 1, actual[cur][pos]);
                        }
                    }
                }
                if (cur == 0) break;
                cur = (cur - 1) & sb;
            }
        }
        for (auto &it : updates) {
            if (dp[get<0>(it)][get<1>(it)] < get<2>(it)) {
                actual[get<0>(it)][get<1>(it)] = SZ_TREE;
                dp[get<0>(it)][get<1>(it)] = get<2>(it);
                his_mask[SZ_TREE] = get<0>(it);
                if (get<3>(it) != -1) {
                    prv_node[SZ_TREE] = get<3>(it);
                }
                else {
                    prv_node[SZ_TREE] = -1;
                }
                SZ_TREE++;
            }
        }
        ptr = nptr + 1;
    }

    int best = 0;
    for (int pos = 1; pos < n; pos++) {
        if (dp[(1 << n) - 1][pos] > dp[(1 << n) - 1][best]) {
            best = pos;
        }
    }
    cout << n - dp[(1 << n) - 1][best] << '\n';
    int cur_v = actual[(1 << n) - 1][best];

    vector<int> way;
    while (cur_v != -1) {
        way.emplace_back(his_mask[cur_v]);
        cur_v = prv_node[cur_v];
    }
    reverse(way.begin(), way.end());
    for (int z = way.size() - 1; z > 0; z--) {
        way[z] ^= way[z - 1];
    }
    vector<pair<int, int>> masks;
   
    int lst = -1;
    for (int z = 0; z < way.size(); z++) {
        lst++;
        while (!(way[z] & (1 << lst))) lst++;
        masks.emplace_back(way[z], lst);
    }

    vector<int> id(n);

    iota(id.begin(), id.end(), 0);
    int DDD = 0;
    vector<int> sss;
    for (int t = 0; t + 1 < masks.size(); t++) {
        assert(masks[t].second < masks[t + 1].second);
    }
    for (int t = 0; t < masks.size(); t++) {
        assert(masks[t].first & (1 << masks[t].second));
        assert((DDD & masks[t].first) == 0);
        DDD |= masks[t].first;
        int c = 0;
        for (int x = 0; x < n; x++) {
            if (masks[t].first & (1 << x)) {
                c += a[x];
            }
        }
        sss.emplace_back(c);
    }
    for (int z = 0; z + 1 < sss.size(); z++) {
        assert(sss[z] < sss[z + 1]);
    }
//    assert(DDD == ((1 << n) - 1));

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    int cnt_op = 0;
    for (int z = 0; z < masks.size(); z++) {
        int cur_m = masks[z].first;
        int cur_pos = masks[z].second;
        for (int t = 0; t < n; t++) {
            if (t == cur_pos) continue;
            if (cur_m & (1 << t)) {
//                assert(0 <= id[t] && id[t] < b.size());
//                assert(0 <= id[cur_pos] && id[cur_pos] < b.size());
                assert(id[t] != id[cur_pos]);
                cout << id[t] + 1 << " " << id[cur_pos] + 1 << '\n';
                cnt_op++;
                b[id[cur_pos]] += b[id[t]];
                int pos = id[t];
                for (int a = pos + 1; a < b.size(); a++) {
                    b[a - 1] = b[a];
                }
                id[t] = -1;
                b.pop_back();
                for (int x = t + 1; x < n; x++) {
                    if (id[x] != -1) id[x]--;
                }
            }
        }
    }
//    assert(cnt_op == n - dp[(1 << n) - 1][best]);
//    for (int z = 0; z + 1 < b.size(); z++) {
//        assert(b[z] < b[z + 1]);
//    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst = 1;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}