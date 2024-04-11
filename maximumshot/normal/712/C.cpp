#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;
int const DELT = 201005;

inline int sum(int a, int b) { return (a + b) % mod; }
inline int mul(int a, int b) { return (1ll * a * b) % mod; }
inline int raz(int a, int b) { return ((a - b) % mod + mod) % mod; }

bool solve() {

    int x, y;
    cin >> x >> y;

    int a, b, c;

    a = b = c = y;

    int res = 0;

    while(a < x || b < x || c < x) {
        vec< int > mas = {a, b, c};
        sort(ALL(mas));
        a = mas[0];
        b = mas[1];
        c = mas[2];
        a = min(x, b + c - 1);
        res++;
    }

    cout << res << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}