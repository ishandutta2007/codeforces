#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("Ofast, unroll-loops", "omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e4 + 10;
const int maxQ = 1e4 + 10;
const int BLOCK = 175;
int n, q;
int idW[maxN];
int idH[maxN];
ll w[maxN], h[maxN];
int a[maxN], b[maxN];
int cur[maxN];
bool mark[maxN];
ll table[15 * BLOCK][16][16];
ll val[16];
ll nval[16];
int ncur[maxN];
void do_jump(int x) {
    for (int t = 0; t < 16; t++) {
        nval[t] = -1e18;
    }
    for (int was = 0; was < 16; was++) {
        if (val[was] < 0) continue;
        for (int withA = 0; withA <= 3; withA++) {
            if (((was & 2) != 0) != (withA == 0)) continue;
            if (!(was & 8) && (withA == 1)) continue;
            if (withA <= 2 && cur[x] == x - 2 + withA) continue;
            for (int withB = 0; withB <= 3; withB++) {
                if (((was & 1) != 0) != (withB == 0)) continue;
                if (!(was & 4) && (withB == 1)) continue;
                if ((withA == 2) != (withB == 2)) continue;
                if (withB <= 2 && cur[x - 2 + withB] == x) continue;
                ll cost = 0;
                if (withA < 2) {
                    cost += w[x] * h[x - 2 + withA];
                }
                if (withB < 2) {
                    cost += h[x] * w[x - 2 + withB];
                }
                if (withA == 2) {
                    cost += w[x] * h[x];
                }
                int new_mask = (was >> 2) + 4 * (withA == 3) + 8 * (withB == 3) - 2 * (withA == 1) - 1 * (withB == 1);
                nval[new_mask] = max(nval[new_mask], val[was] + cost);
            }
        }
    }
    for (int t = 0; t < 16; t++) {
        val[t] = nval[t];;
    }
    //11
    //00
//    cout << " ------ " << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    vector<pair<ll, int>> ww;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        ww.emplace_back(w[i], i);
    }
    sort(ww.begin(), ww.end());
    for (int i = 1; i <= n; i++) {
        idW[ww[i - 1].second] = i;
        w[i] = ww[i - 1].first;
    }
    vector<pair<ll, int>> hh;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        hh.emplace_back(h[i], i);
    }
    sort(hh.begin(), hh.end());
    for (int i = 1; i <= n; i++) {
        idH[hh[i - 1].second] = i;
        h[i] = hh[i - 1].first;
    }
    for (int i = 1; i <= n; i++) {
        cur[idW[i]] = idH[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
        a[i] = idW[a[i]];
        b[i] = idW[b[i]];
    }
    for (int i = 0; i < q; i += BLOCK) {
        int from = i;
        int to = min(i + BLOCK, q);
        memset(mark, 0, sizeof mark);
        memcpy(ncur, cur, sizeof cur);
        for (int j = from; j < to; j++) {
            mark[a[j]] = mark[b[j]] = true;
            mark[ncur[a[j]]] = mark[ncur[b[j]]] = true;
            swap(ncur[a[j]], ncur[b[j]]);
        }
        int ptr = 1;
        vector<pair<int, int>> groups;
        while (ptr <= n) {
            if (mark[ptr]) {
                groups.emplace_back(ptr, ptr);
                ptr++;
                continue;
            }
            int nptr = ptr;
            while (nptr <= n && !mark[nptr]) nptr++;
            nptr--;
            groups.emplace_back(ptr, nptr);
            ptr = nptr + 1;
        }
//        for (auto& it : groups) {
//            cout << it.first << " " << it.second << endl;
//        }
//        cout << " ---- " << endl;
        assert(groups.size() < 15 * BLOCK);
        for (int a = 0; a < groups.size(); a++) {
            int l = groups[a].first;
            int r = groups[a].second;
            if (l != r) {
                //1 free now
                for (int mask = 0; mask < 16; mask++) {
                    if ((mask & 3) && l <= 2) continue;
                    if ((mask & 12) && l <= 1) continue;
                    for (int z = 0; z < 16; z++) {
                        val[z] = -1e18;
                    }
                    val[mask] = 0;
                    for (int x = l; x <= r; x++) {
                        do_jump(x);
                    }
                    for (int t = 0; t < 16; t++) {
                        table[a][mask][t] = val[t];
                    }
                }
            }
        }
        for (int id = from; id < to; id++) {
            swap(cur[a[id]], cur[b[id]]);
            for (int z = 0; z < 16; z++) {
                val[z] = -1e18;
            }
            val[0] = 0;
            for (int a = 0; a < groups.size(); a++) {
                int l = groups[a].first;
                int r = groups[a].second;
                if (l != r) {
                    const ll INF = 1e18;
                    for (int t = 0; t < 16; t++) {
                        nval[t] = -INF;
                    }
                    for (int was = 0; was < 16; was++) {
                        if (val[was] < 0) continue;
                        for (int will = 0; will < 16; will++) {
                            nval[will] = max(nval[will], val[was] + table[a][was][will]);
                        }
                    }
                    for (int was = 0; was < 16; was++) {
                        val[was] = nval[was];
                    }
                }
                else {
                    do_jump(l);
                }
            }
            cout << val[0] << '\n';
        }
    }

    return 0;
}