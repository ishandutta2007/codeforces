/*input
9
1
2
3
4
5
6
7
8
9

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
#define debug(x...) {cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
// const int N =;
vector<int> bound;
int findFirst(int n) {
    for (int i = 0;; i += 2) {
        if (n > (1LL << i)) {
            n -= (1LL << i);
            continue;
        }
        return (1LL << i) + n - 1;
    }
    assert(false);
}

int which(int x) {
    int p = (upper_bound(bound.begin(), bound.end(), x) - bound.begin() - 1) % 3;
    return p;
}

int hbit(int x) {
    int sub = 63 - __builtin_clzll(x);
    return (1LL << sub);
}

int rem1bit(int x) {
    int sub = 63 - __builtin_clzll(x);
    return (x - (1LL << sub));
}

int rem2bit(int x) {
    return rem1bit(rem1bit(x));
}

vector<int> trace(int x) {
    if (x == 0) return {0, 0, 0};
    int order = which(x), base = hbit(x);
    vector<int> ret(3, 0);
    if (order != 0) base /= 2;
    for (int i = 1; i <= 3; i++) {
        int t = (order + i); if (t > 3) t -= 3;
        ret[i - 1] += base * t;
    }
    // if (x == 8) {
    //     print("X", ret);
    // }
    vector<int> rec;
    if (order == 2) rec = trace(rem2bit(x));
    else rec = trace(rem1bit(x));
    // print(x, rem1bit(x), rec, ret);
    loop(i, 0, 2) ret[i] += rec[i];
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i <= 61; i += 2) {
        bound.push_back((1LL << i));
        bound.push_back((1LL << (i + 1)));
        bound.push_back((1LL << i) + (1LL << (i + 1)));
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        auto rec = trace(findFirst((n + 2) / 3));
        cout << rec[(n + 2) % 3] << endl;
    }
}