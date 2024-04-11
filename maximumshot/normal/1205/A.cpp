#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

bool check(vector<int> a) {
    int n = (int) a.size();
    n /= 2;
    int mn = inf;
    int mx = -inf;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += a[(i + j) % (2 * n)];
        }
        mn = min(mn, tmp);
        mx = max(mx, tmp);
    }
    return mx - mn <= 1;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }

    vector<int> a(2 * n);

    for (int i = 0; i < n; i++) {
        int x = 2 * i + 1;
        a[2 * i] = x;
        a[(2 * i + n) % (2 * n)] = x % 2 ? x + 1 : x - 1;
    }

//    assert(check(a));

    cout << "YES\n";
    for (int i = 0; i < 2 * n; i++) {
        cout << a[i] << " ";
    }

    cout << "\n";

    return 0;
}