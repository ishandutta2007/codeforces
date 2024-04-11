/*input
2 10 13 49
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

int A, B, C, D;
int sumf(int l, int r) {
    return (r - l + 1) * (l + r) / 2;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> A >> B >> C >> D;
    int nsub = 0;
    loop(i, A, B) {
        int zr = D + 1;
        int lb = max(B, C - i); // 1
        int hb = min(C, D - i); // D-C+1
        if (lb > hb) continue;
        // print(i, zr - hb - i, zr - lb - i);
        int more = sumf(zr - hb - i, zr - lb - i) + (lb - B) * (D - C + 1);
        nsub += more;
        // print(i, more);
    }
    // 1 2 3 4
    // 1
    int ans = (B - A + 1) * (C - B + 1) * (D - C + 1) - nsub;
    cout << ans << endl;
}