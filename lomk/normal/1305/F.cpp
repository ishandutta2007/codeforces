/*input
4
8 1 1 5
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {if (!LOCAL) return; cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if (!LOCAL) return; cout << value << ' '; print(values...);}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

struct SegSieve {
    // use with def int long long
    int L, R;
    vector<vector<int> > divi;
    vector<int> primes, mark;
    void prep() {
        int lim = sqrt(R);
        mark.assign(lim + 1, 0);
        for (int i = 2, en = sqrt(lim); i <= en; i++) if (mark[i] == 0) for (int j = i * i; j <= lim; j += i) mark[j] = i;
        loop(i, 2, lim) if (mark[i] == 0) primes.push_back(i);
        for (auto it : primes) {
            for (int i = max(it * it, L + (it - L % it) % it); i <= R; i += it) divi[i - L].push_back(it);
        }
        loop(i, L, R) {
            int cur = i;
            for (auto it : divi[i - L]) while (cur % it == 0) cur /= it;
            if (cur > 1) divi[i - L].push_back(cur);
        }
    }
    vector<int> fact(int X) {
        assert(L <= X && X <= R);
        return divi[X - L];
    }
    // make sure L<=R from outside
    SegSieve(int _L, int _R): L(_L), R(_R), divi(vector < vector<int> > (_R - _L + 1, vector<int>())) {prep();};
    SegSieve() {};
} era;

int n;
vector<int> a;

int ans;
unordered_map<int, int> mark;
int cal(int mod) {
    if (mark.find(mod) != mark.end()) return mark[mod];
    int ret = 0;
    for (auto it : a) {
        int t = it % mod;
        if (t >= mod - t || it == t) ret += mod - t;
        else ret += t;
        if (ret >= ans) break;
    }
    return mark[mod] = ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    loop(i, 1, n) {
        int t; cin >> t;
        a.push_back(t);
    }
    ans = n;
    ans = min(ans, cal(2));
    ans = min(ans, cal(3));
    if (ans != 0) {
        era = SegSieve(max(1LL, a[0] - ans), a[0] + ans);
        for (int i = 0; i < ans; i++) {
            auto check = [&](int p, int d) {
                if (d >= ans) return;
                ans = min(ans, cal(p));
            };
            auto rec = era.fact(a[0] + i);
            for (auto it : rec) check(it, i);
            if (i < ans && a[0] - i >= 1) {
                rec = era.fact(a[0] - i);
                for (auto it : rec) check(it, i);
            }
        }
    }
    cout << ans << endl;
}