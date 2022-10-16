/*input
10
1010111110
1011101101
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

int n;
string S, T;
set<int> st[2];

int solve() {
    int ans = 0;
    while (!st[0].empty() && !st[1].empty()) {
        int sta = *st[0].begin(); int tick = 0; int root = 0; ans++;
        int cnt = 0;
        if (*st[1].begin() < sta) {
            sta = *st[1].begin();
            tick = root = 1;
        }
        while (true) {
            st[tick].erase(sta); cnt++;
            tick ^= 1;
            auto iter = st[tick].upper_bound(sta);
            if (iter == st[tick].end()) {
                if (tick == root) break;
                else {
                    if (cnt == 1) return -1;
                    st[tick ^ 1].insert(sta);
                    break;
                }
            }
            else
                sta = *iter;
        }
    }
    if (!st[0].empty() || !st[1].empty()) return -1;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> S >> T;
    loop(i, 0, n - 1) {
        if (S[i] == T[i]) continue;
        if (S[i] == '0') st[0].insert(i);
        else st[1].insert(i);
    }
    cout << solve() << endl;
}