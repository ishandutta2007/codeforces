/*input
0 6


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
#define all(x) (x).begin(), (x).end()
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define debug(x...) {if (!LOCAL) return; cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if (!LOCAL) return; cout << value << ' '; print(values...);}
// const int N =;

pair<int, int> compute(int S, int X) {
    int A = (S - X) / 2;

    int a = 0, b = 0;
    // Traverse through all bits
    loop(i, 0, 62) {
        if (bit(X, i) == 0 && bit(A, i) == 0);
        else if (bit(X, i) == 0 && bit(A, i) > 0) {
            a = ((1LL << i) | a);
            b = ((1LL << i) | b);
        }
        else if (bit(X, i) > 0 && bit(A, i) == 0) {
            a = ((1LL << i) | a);
        }
        else {
            return { -1, -1};
        }
    }
    return {a, b};
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    if (a == 0 && b == 0) {
        cout << 0 << endl;
        exit(0);
    }
    if (a > b || (b - a) % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    if (a == b) {
        cout << 1 << endl;
        cout << a << endl;
        return 0;
    }
    auto rec = compute(b, a);
    if (rec.fi != -1) {
        cout << 2 << endl;
        cout << rec.fi << sp << rec.se << endl;
        return 0;
    }
    cout << 3 << endl;
    cout << a << sp << (b - a) / 2 << sp << (b - a) / 2 << endl;
}