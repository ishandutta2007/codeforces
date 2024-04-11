#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int k;
const int maxN = 17;
vector < int > all[maxN];
map < ll, int > mp;
bool used[maxN];
vector < pair < int, pair < int, int > > > inf[(1 << maxN)];
bool is_good[(1 << maxN)];
ll sm[maxN];
int prv[(1 << maxN)];
bool can[(1 << maxN)];
int c[maxN], p[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> k;
    ll total = 0;
    for (int i = 1; i <= k; i++) {
        int v;
        cin >> v;
        all[i].resize(v);
        for(int& x : all[i]) {
            cin >> x;
            total += x;
            mp[x] = i;
            sm[i] += x;
        }
    }
    if (total % k != 0) {
        cout << "No";
        return 0;
    }
    total /= k;
    for (int i = 1; i <= k; i++) {
        for (int v : all[i]) {
            memset(used, 0, sizeof used);
            int cur = i;
            bool ok = true;
            ll take_now = v;
            vector < pair < int, pair < int, int > > > ans;
            int msk = 0;
            int st = cur;
            int start_take = v;
            while (!used[cur]) {
                //cout << cur << " here" << endl;
                //cout << cur << " " << take_now << endl;
                msk |= (1 << (cur - 1));
                used[cur] = true;
                ll need = total + take_now - sm[cur];
                if (!mp.count(need)) {
                    ok = false;
                    break;
                }
                int who = mp[need];
                if (used[who] && who != st) {
                    ok = false;
                    break;
                }
                if (used[who] && who == st && start_take != need) {
                    ok = false;
                    break;
                }
                take_now = need;
                ans.emplace_back(need, make_pair(who, cur));
                cur = who;
            }
            if (ok && inf[msk].empty()) {
                is_good[msk] = true;
                inf[msk] = ans;
            }
        }
    }
    can[0] = true;
    for (int i = 0; i < (1 << k); i++) {
        if (!can[i]) continue;
        int other = ((1 << k) - 1) ^ i;
        int sb = other;
        while (sb > 0) {
            if (is_good[sb]) {
                can[sb | i] = true;
                prv[sb | i] = sb;
            }
            sb = (sb - 1) & (other);
        }
    }
    int hs = (1 << k) - 1;
    if (!can[hs]) {
        cout << "No";
        return 0;
    }
    while (hs > 0) {
        int pp = prv[hs];
        for (auto it : inf[pp]) {
            c[it.second.first] = it.first;
            p[it.second.first] = it.second.second;
        }
        hs ^= pp;
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= k; i++) {
        cout << c[i] << " " << p[i] << '\n';
    }
    return 0;
}