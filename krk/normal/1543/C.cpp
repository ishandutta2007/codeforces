#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const ld eps = 1e-12l;

int T;
ld v;
map <ldld, ld> M;

ld Solve(ld a, ld b)
{
    if (a < b) swap(a, b);
    if (a <= eps) return 1;
    auto it = M.find(ldld(a, b));
    if (it != M.end()) return it->second;
    ld cur = 0;
    if (b <= eps) cur = 1 + a * Solve(a - min(a, v), 0);
    else cur = 1 + a * (a > v? Solve(a - v, b + v / 2): Solve(0, b + a / 2)) + b * (b > v? Solve(a + v / 2, b - v): Solve(a + b / 2, 0));
    return M[ldld(a, b)] = cur;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        ld a, b, c; cin >> a >> b >> c;
        cin >> v;
        M.clear();
        cout << fixed << setprecision(10) << Solve(a, b) << endl;
    }
    return 0;
}