#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int inf = 1e9;
const ll inf64 = 1e18;

struct pt {
    ll x = 0, y = 0;
    pt() = default;
    pt(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    void read() {
        cin >> x >> y;
    }
    ll vector_mul(const pt &o) const {
        return x * o.y - o.x * y;
    }
    pt operator - (const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
};

const int N = 2005;

int n;
pt p[N];
char s[N];
int used[N];
int ot[N], sz;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        p[i].read();
    }

    cin >> s;

    int cur = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].x < p[cur].x) {
            cur = i;
        } else if (p[i].x == p[cur].x && p[i].y < p[cur].y) {
            cur = i;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << cur + 1 << " ";
        used[cur] = 1;
        if (i == n - 2) break;
        sz = 0;
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            ot[sz++] = j;
        }
        sort(ot, ot + sz, [&](int p1, int p2){
            return (p[p1] - p[cur]).vector_mul(p[p2] - p[cur]) < 0;
        });
        if (s[i] == 'L') {
            cur = ot[sz - 1];
        } else {
            cur = ot[0];
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cout << i + 1 << "\n";
        }
    }

    return 0;
}