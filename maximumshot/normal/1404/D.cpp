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

bool solve(vector<int> a, vector<int> b) {
    int n = (int) a.size();
    int md = 2 * n;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sm = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask)
                sm = (sm + a[i]) % md;
            else
                sm = (sm + b[i]) % md;
        }
        if (sm == 0) {
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask)
                    cout << "[" << a[i] << "] " << b[i] << "\n";
                else
                    cout << a[i] << " [" << b[i] << "]\n";
            }
            return true;
        }
    }
    return false;
}

void help(int n) {
    for (int mask = 0; mask < (1 << (2 * n)); mask++) {
        if (__builtin_popcount(mask) != n)
            continue;
        vector<int> a, b;
        for (int i = 0; i < 2 * n; i++) {
            if ((1 << i) & mask)
                b.push_back(i);
            else
                a.push_back(i);
        }
        do {
            if (!solve(a, b)) {
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " " << b[i] << "\n";
                }
                return;
            }
        } while (next_permutation(a.begin(), a.end()));
    }
}

int main() {

#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 0; i < 2 * n; i++)
            cout << i % n + 1 << " ";
        cout << endl;
        int res;
        cin >> res;
        return 0;
    }

    cout << "Second" << endl;

    vector<int> one(n + 1, -1), two(n + 1, -1);

    for (int i = 1; i <= 2 * n; i++) {
        int x;
        cin >> x;
        if (one[x] == -1)
            one[x] = i;
        else
            two[x] = i;
    }

    vector<int> take(2 * n + 1);
    vector<vector<tuple<int, int, int>>> g(n);
    vector<int> used(n);

    for (int i = 1; i <= n; i++) {
        int u = one[i], v = two[i];
        if (u % n == v % n) {
            take[u] = 1;
            used[u % n] = 1;
//            cout << u << " !\n";
            continue;
        }
        g[u % n].emplace_back(v % n, v, i);
        g[v % n].emplace_back(u % n, u, i);

//        cout << u % n << " " << v % n << " | " << u << " " << v << "\n";
    }

    for (int v = 0; v < n; v++) {
        if (used[v])
            continue;
        int cur = get<0>(g[v][0]), start_e = get<2>(g[v][0]);
        vector<int> es = {start_e}, vs = {get<1>(g[v][0])};
        int prv_e = start_e;
        while (1) {
            int any = 0;
            for (auto e : g[cur]) {
                auto [nxt, V, eid] = e;
                if (eid == prv_e || eid == start_e)
                    continue;
                cur = nxt;
                prv_e = eid;
                any = 1;
                es.push_back(eid);
                vs.push_back(V);
                break;
            }
            if (!any)
                break;
        }
        for (int e : es)
            used[one[e] % n] = used[two[e] % n] = 1;
        for (int u : vs)
            take[u] = 1;
    }

    int md = 2 * n, sm = 0;

    for (int v = 1; v <= 2 * n; v++)
        if (take[v])
            sm = (sm + v) % md;

//    cout << sm << " ?\n";

    if (sm != 0) {
        for (int v = 1; v <= 2 * n; v++)
            take[v] ^= 1;
    }

    for (int v = 1; v <= 2 * n; v++)
        if (take[v])
            cout << v << " ";

    cout << endl;

    return 0;
}