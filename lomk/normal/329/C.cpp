/*input
5 4
1 2
2 3
3 4
4 1
*/
#ifdef UncleGrandpa
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define debug(x...) {if constexpr(LOCAL)cout << "[" << #x << "] ="; print(x);}
void print() {if constexpr(LOCAL)cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if constexpr(LOCAL)cout << value << ' ', print(values...);}
// const int N =;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

#define ull unsigned long long
struct custom_hash {
    static ull splitmix64(ull x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<int, int> x) const {
        static const ull FIXED_RANDOM1 = chrono::steady_clock::now().time_since_epoch().count();
        static const ull FIXED_RANDOM2 = chrono::steady_clock::now().time_since_epoch().count();
        return hash<ull>()(splitmix64(x.first + FIXED_RANDOM1) ^ splitmix64(x.second + FIXED_RANDOM2));
    }
};

using hashmap = unordered_map<pair<int, int>, bool, custom_hash>;

hashmap mark;
int n, m;
hashmap ans;

bool check(vector<int> &a) {
    ans.clear();
    loop(i, 0, a.size() - 1) {
        if (a[i] == i || mark.find(minmax(a[i], i)) != mark.end() || ans.find(minmax(a[i], i)) != ans.end())
            shuffle(a.begin() + i, (i + 4 < a.size() ? a.begin() + i + 5 : a.end()), rd);
        if (a[i] != i && mark.find(minmax(a[i], i)) == mark.end()) {
            ans[minmax(a[i], i)] = true;
            if (ans.size() >= m) return true;
        }
        if (a.size() - (i + 1) + ans.size() < m) return false;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    mark.max_load_factor(0.25);
    mark.reserve(m);
    loop(i, 1, m) {
        int u, v; cin >> u >> v; u--; v--;
        mark[minmax(u, v)] = true;
    }
    vector<int> a; loop(i, 0, n - 1) a.push_back(i);
    while (true) {
        shuffle(a.begin(), a.end(), rd);
        if (check(a)) {
            for (auto it : ans)
                cout << it.fi.fi + 1 << sp << it.fi.se + 1 << endl;
            return 0;
        }
        if (1.0 * clock() / CLOCKS_PER_SEC >= 0.25) break;
    }
    cout << -1 << endl;
}