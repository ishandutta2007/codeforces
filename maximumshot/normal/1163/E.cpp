#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 1 << 20;

int n;
vector<int> basis;
int u[X];
int xx[X];

bool check(int sz) {
    basis.clear();
    int S = 1 << sz;
    fill(u, u + S, 0);
    u[0] = 1;
    for (int x, i = 0; i < n; i++) {
        x = xx[i];
        if (x >= S) continue;
        if (u[x]) continue;
        basis.push_back(x);
        for (int y = 0; y < X; y++) {
            u[y ^ x] |= u[y];
        }
    }
    return (int)basis.size() == sz;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> xx[i];
    }

    int sz = 20;

    while (sz > 0 && !check(sz)) sz--;

    if (sz == 0) {
        cout << "0\n0\n";
        return 0;
    }

    vector<int> ans, nxt;

    ans.push_back(0);

    for (int i = 1; i < sz; i++) {
        nxt.clear();
        nxt.push_back(i);
        for (int x : ans) {
            nxt.push_back(x);
        }
        nxt.push_back(i);
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        for (int x : ans) {
            nxt.push_back(x);
        }
        ans = nxt;
    }

    cout << sz << "\n";

    int x = 0;

    cout << x << " ";

    for (int xr : ans) {
        x ^= basis[xr];
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}