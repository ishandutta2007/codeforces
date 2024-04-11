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

int f(char c) {
    return c == 'R' ? 0 : c == 'S' ? 1 : 2;
}

const int N = 2e5 + 5;

int n, q;
int a[N];
int fen[3][N];
int tot[3];
set<int> pos[3];

void add(int i, int p, int x) {
    for (int cur = p; cur < N; cur |= (cur + 1)) {
        fen[i][cur] += x;
    }
}

int get(int i, int p) {
    int res = 0;
    for (int cur = p; cur >= 0; cur = (cur & (cur + 1)) - 1) {
        res += fen[i][cur];
    }
    return res;
}

int query() {
    if (tot[0] == n || tot[1] == n || tot[2] == n) {
        return n;
    }
    for (int i = 0; i < 3; i++) {
        if (tot[i] == 0) {
            return tot[(i + 1) % 3];
        }
    }
    int L = inf;
    int R = inf;
    for (int i = 0; i < 3; i++) {
        int p = *pos[i].begin();
        if (p != 0) L = min(L, p);
        p = *(--pos[i].end());
        if (p != n - 1) {
            R = min(R, n - p - 1);
        }
    }
    int l = L;
    int r = n - 1 - R;
    int res = L + R;
    for (int x = 0; x < 3; x++) {
        int ql = *pos[(x + 1) % 3].begin();
        int qr = *(--pos[(x + 1) % 3].end());
        ql = max(ql, l);
        qr = min(qr, r);
        if (ql <= qr) res += get(x, qr) - get(x, ql - 1);
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = f(c);
        tot[a[i]]++;
        pos[a[i]].insert(i);
        add(a[i], i, +1);
    }

    cout << query() << "\n";

    for (int iter = 0; iter < q; iter++) {
        int i;
        char c;
        cin >> i >> c;
        i--;
        int x = f(c);

        pos[a[i]].erase(i);
        add(a[i], i, -1);
        tot[a[i]]--;

        a[i] = x;
        pos[a[i]].insert(i);
        add(a[i], i, +1);
        tot[a[i]]++;

        cout << query() << "\n";
    }

    return 0;
}