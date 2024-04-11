#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
ll a, b, c;
void solve() {
    ll best = 0;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    ll free_ones = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == '1' && s[i + 1] == '1') free_ones++;
    }
    vector<ll> good;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == '1' && s[i + 1] == '0') {
            int ptr = i + 1;
            while (ptr < s.size() && s[ptr] == '0') ptr++;
            if (ptr == s.size()) continue;
            assert(s[ptr] == '1');
            good.emplace_back(ptr - i - 1);
        }
    }
    //first zero
    ll free_zeroes = 0;
    ll tot_zeroes = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == '0' && s[i + 1] == '0') free_zeroes++;

    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') tot_zeroes++;
    }
    ll c_zeroes = free_zeroes;
    ll c_ones = free_ones;
    sort(good.begin(), good.end());
    reverse(good.begin(), good.end());
    vector<ll> c_good = good;
    for (int step = 0; step < 2; step++) {
        ll cur_cost = 0;
        int zero_m = 0;
        int one_m = 0;
        int cur_tot = 0;
        int used_free = 0;
        int can = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == step % 2) {
                if (free_ones > 0) {
                    free_ones--;
                    cur_cost += b;
                }
                else {
                    if (can) {
                        can--;
                        cur_cost += b;
                    }
                    else {
                        if (good.empty()) break;
                        if (zero_m < good.back()) break;
                        zero_m -= good.back();
                        if (used_free > 0) {
                            free_zeroes++;
                            used_free--;
                            cur_cost -= a;
                            cur_cost -= c;
                        }
                        cur_cost += b;
                        good.pop_back();
                        can++;
                        can--;
                    }
                }
            }
            else {
                if (cur_tot == tot_zeroes) break;
                if (free_zeroes > 0) {
                    free_zeroes--;
                    used_free++;
                    cur_cost += a;
                    zero_m += 1;
                    cur_tot++;
                }
                else {
                    cur_cost -= c;
                    zero_m += 1;
                    cur_tot++;
                    if (!good.empty()) {
                        can++;
                        good.pop_back();
                    }
                }
            }
            best = max(best, cur_cost);
        }
        free_zeroes = c_zeroes;
        free_ones = c_ones;
        good = c_good;
    }
    cout << best << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}