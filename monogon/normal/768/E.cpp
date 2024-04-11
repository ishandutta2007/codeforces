
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// if we can compute the answer for one pile, use
// grundy numbers to find overall answer.
// how many states in a single pile of 60?
// number of stones in pile K, and subset of numbers with sum <= 60 - K

const int N = 1e6 + 5, M = 1e9 + 9;
int n, s[N];
map<int, int> grundy = {
{0, 0},
{1, 1},
{2, 1},
{3, 2},
{4, 2},
{5, 2},
{6, 3},
{7, 3},
{8, 3},
{9, 3},
{10, 4},
{11, 4},
{12, 4},
{13, 4},
{14, 4},
{15, 5},
{16, 5},
{17, 5},
{18, 5},
{19, 5},
{20, 5},
{21, 6},
{22, 6},
{23, 6},
{24, 6},
{25, 6},
{26, 6},
{27, 6},
{28, 7},
{29, 7},
{30, 7},
{31, 7},
{32, 7},
{33, 7},
{34, 7},
{35, 7},
{36, 8},
{37, 8},
{38, 8},
{39, 8},
{40, 8},
{41, 8},
{42, 8},
{43, 8},
{44, 8},
{45, 9},
{46, 9},
{47, 9},
{48, 9},
{49, 9},
{50, 9},
{51, 9},
{52, 9},
{53, 9},
{54, 9},
{55, 10},
{56, 10},
{57, 10},
{58, 10},
{59, 10},
{60, 10},
};
// map<ll, int> dp;

// int mex(vi &v) {
//     int n = v.size();
//     int i = 0;
//     while(i < n && v[i] == i) i++;
//     return i;
// }

// int grundy(int k, vi moves) {
//     ll hash = 0;
//     for(int x : moves) {
//         hash = (127 * hash + x) % M;
//     }
//     hash = (127 * hash + k) % M;
//     if(dp.count(hash)) return dp[hash];
//     vi ve;
//     rep(i, 1, k + 1) {
//         if(!binary_search(all(moves), i)) {
//             vi v2(all(moves));
//             v2.push_back(i);
//             sort(all(v2));
//             ve.push_back(grundy(k - i, v2));
//         }
//     }
//     sort(all(ve));
//     ve.erase(unique(all(ve)), ve.end());
//     return dp[hash] = mex(ve);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // vi emp = {};
    // rep(i, 0, 61) {
    //     grundy(i, emp);
    //     cout << "{" << i << ", " << dp[i] << "}," << endl;
    //     dp.clear();
    // }
    cin >> n;
    int g = 0;
    rep(i, 0, n) {
        cin >> s[i];
        g ^= grundy[s[i]];
    }
    cout << (g == 0 ? "YES" : "NO") << '\n';
}