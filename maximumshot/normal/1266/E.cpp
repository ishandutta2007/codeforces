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

const int N = 2e5 + 5;

int n, q;
int a[N];

struct Query {
    int s, t, u;
} qs[N];

map<int, int> ach[N];

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> qs[i].s >> qs[i].t >> qs[i].u;
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i];

    for (int i = 0; i < q; i++) {
        int s, t, u;
        s = qs[i].s, t = qs[i].t, u = qs[i].u;
        auto fnd = ach[s].find(t);
        if (fnd != ach[s].end()) {
            int pos = fnd->second;
            sum -= max(0, a[pos]);
            a[pos]++;
            sum += max(0, a[pos]);
            ach[s].erase(fnd);
        }
        if (u != 0) {
            sum -= max(0, a[u]);
            ach[s][t] = u;
            a[u]--;
            sum += max(0, a[u]);
        }
        cout << sum << "\n";
    }

    return 0;
}