#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = (int)1e9;
const ll md = (ll)1e9 + 7, inf64 = (ll)1e18;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    set<pii> us;
    while (m--) {
        int a, b;
        cin >> a >> b, a--, b--;
        if (a > b)
            swap(a, b);
        us.insert({a, b});
    }

    pii cur = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (us.find({i, j}) == us.end()) {
                cur = {i, j};
                break;
            }
        }
    }

    if (cur.first == -1) {
        cout << "NO\n";
        return 0;
    }

    vector<int> v(n);
    int x = cur.first, y = cur.second;
    v[x] = n - 1, v[y] = n;
    int cn = 1;
    for (int i = 0; i < n; i++) {
        if (i == x || i == y)
            continue;
        v[i] = cn++;
    }

    cout << "YES\n";
    for (int x : v)
        cout << x << ' ';
    cout << '\n';
    v[y] = n - 1;
    for (int x : v)
        cout << x << ' ';
    cout << '\n';

    return 0;
}