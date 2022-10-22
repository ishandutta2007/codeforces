#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

struct Fen {
    int n = 0; // [0, n)
    vector<int> f;

    Fen() = default;

    Fen(int nn) {
        n = nn;
        f.resize(n);
    }

    void add(int p, int x) {
        for (int cur = p; cur < n; cur |= (cur + 1)) {
            f[cur] += x;
        }
    }

    int get(int p) {
        int res = 0;
        for (int cur = p; cur >= 0; cur = (cur & (cur + 1)) - 1) {
            res += f[cur];
        }
        return res;
    }
};

const int inf = 1e9;
const ll inf64 = 1e18;

struct pt {
    int x, y;

    bool operator < (const pt& o) const {
        return (x < o.x) || (x == o.x && y < o.y);
    }
};

const int N = 2e5 + 5;

int n;
pt p[N];

void updx() {
    sort(p, p + n);
    vector<pt> q;
    for (int i = 0; i < n; i++) {
        if (!i || p[i].x != p[i - 1].x) {
            q.push_back(p[i]);
        }
    }
    n = (int) q.size();
    for (int i = 0; i < n; i++) {
        p[i] = q[i];
    }
}

void compressx() {
    vector<int> crd;
    for (int i = 0; i < n; i++) {
        crd.push_back(p[i].x);
    }
    sort(crd.begin(), crd.end());
    for (int i = 0; i < n; i++) {
        p[i].x = lower_bound(crd.begin(), crd.end(), p[i].x) - crd.begin();
    }
}



int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

//    updx();

    sort(p, p + n, [&](const pt& p1, const pt& p2) {
        return (p1.y > p2.y) || (p1.y == p2.y && p1.x < p2.x);
    });

    compressx();

    Fen fen(n);
    ll res = 0;

    vector<int> was_x(n);

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && p[i].y == p[j].y) j++;
        j--;
        for (int q = i; q <= j; q++) {
            if (!was_x[p[q].x]) {
                was_x[p[q].x] = 1;
                fen.add(p[q].x, 1);
            }
        }
        for (int q = i; q <= j; q++) {
            int l = 0;
            if (q > 0 && p[q].y == p[q - 1].y) {
                l = p[q - 1].x + 1;
            }
            int cl = l <= p[q].x ? fen.get(p[q].x - 1) - fen.get(l - 1) : 0;
            int cr = p[q].x + 1 <= n - 1 ? fen.get(n - 1) - fen.get(p[q].x) : 0;
            res += 1ll * (cl + 1) * (cr + 1);
        }
        i = j;
    }

    cout << res << "\n";

    return 0;
}