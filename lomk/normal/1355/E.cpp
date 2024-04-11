/*input
3 1 100 100
1 3 8
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

int n, A, R, M;
vector<int> a;
vector<int> sl, sr;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> A >> R >> M;
    M = min(M, A + R);
    loop(i, 1, n) {
        int t; cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    for (auto it : a) {
        int pre = (sl.empty() ? 0 : sl.back());
        sl.push_back(pre + it);
    }
    rloop(i, a.size() - 1, 0) {
        int pre = (sr.empty() ? 0 : sr.back());
        sr.push_back(pre + a[i]);
    }
    reverse(sr.begin(), sr.end());

    auto cal = [&](int i, int val) {
        int suml = i * val - sl[i - 1];
        int sumr = sr[i] - (n - i) * val;
        int t = min(suml, sumr);
        int ret = t * M;
        suml -= t; sumr -= t;
        if (suml) ret += suml * A;
        else ret += sumr * R;
        return ret;
    };
    int ans = numeric_limits<int>::max() / 2;
    loop(i, 1, a.size() - 1) {
        int l = a[i - 1], r = a[i];
        while (r - l > 2) {
            int mid1 = (l * 2 + r) / 3;
            int mid2 = (l + 2 * r) / 3;
            int val1 = cal(i, mid1); int val2 = cal(i, mid2);
            if (val1 > val2) l = mid1;
            else if (val1 < val2) r = mid2;
            else l = mid1, r = mid2;
        }
        loop(j, l, r) ans = min(ans, cal(i, j));
    }
    cout << ans << endl;
}