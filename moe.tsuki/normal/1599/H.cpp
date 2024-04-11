#include <bits/stdc++.h>
#ifdef KISEKI
#define debug(a...) ckiseki(#a, a)
template <typename ...T> void ckiseki(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((std::cerr << "\e[1;32m(" << s << ") = ("), ... ,(std::cerr << args << (--cnt ? ", " : ")\e[0m\n")));
}
#define orange(a...) kiseki(#a, a)
template <typename T> void kiseki(const char *s, T L, T R) {
    std::cerr << "\e[1;32m[ " << s << " ] = [ ";
    for (int f = 0; L != R; ++L)
        std::cerr << (f++ ? ", " : "") << *L;
    std::cerr << " ]\e[0m\n";
}
#else
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
#define all(v) begin(v),end(v)

using namespace std;
const int C = 1e9;

int ask(int x, int y) {
    cout << "? " << x << ' ' << y << '\n';
    int res;
    cin >> res;
    return res;
}

signed main() {
    // ios_base::sync_with_stdio(0), cin.tie(0);
    int d1 = ask(1, 1);
    int d2 = ask(C, 1);
    // (x-1) + (y-1) = d1
    // (C-x) + (y-1) = d2
    // 2x - 1 - C = d1 - d2
    int jx = (d1 - d2 + C + 1) / 2;
    int yd = ask(clamp(jx, 1, C), 1);
    int ly = 1 + yd;
    debug(ly);
    int lx = d1 + 2 - ly;
    int rx = C-d2-1 + ly;
    debug(d2);
    debug(lx, rx);
    int d3 = ask(1, C);
    // (x-1) + (C-y) = d3
    int ry = C-d3-1 + lx;
    cout << "! " << lx << ' ' << ly << ' ' << rx << ' ' << ry << endl;
}