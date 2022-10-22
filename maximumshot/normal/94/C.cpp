#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;

    cin >> n >> m >> a >> b;

    a--, b--;

    int ia = a / m;
    int ja = a % m;
    int ib = b / m;
    int jb = b % m;

    if (ia == ib) {
        cout << "1\n";
        return 0;
    }

    if (a == 0 && b + 1 == n) {
        cout << "1\n";
        return 0;
    }
    
    if (a == 0 && jb + 1 == m || b + 1 == n && ja == 0) {
        cout << "1\n";
        return 0;
    }

    if (ja == 0 && jb + 1 == m) {
        cout << "1\n";
        return 0;
    }

    if (ia + 1 == ib) {
        cout << "2\n";
        return 0;
    }

    if (ja - 1 == jb) {
        cout << "2\n";
        return 0;
    }

    if (ja == 0 || jb + 1 == m) {
        cout << "2\n";
        return 0;
    }

    if (a == 0 || b == n - 1) {
        cout << "2\n";
        return 0;
    }

    cout << "3\n";

    return 0;
}