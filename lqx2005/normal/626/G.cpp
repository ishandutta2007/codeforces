#include <bits/stdc++.h>
#define x first
#define y second
typedef long long i64;
typedef double db;
using namespace std;
const int N = 2e5 + 10;
struct frac {
    i64 x, y;
    friend bool operator < (const frac a, const frac b) {
        return a.x * b.y < b.x * a.y;
    }
};
int n, t, q, p[N], l[N], tick[N];
db sum = 0;
int cnt = 0;
set<pair<frac, int> > in, out;

pair<frac, int> f(int x, int y) {
    return {frac{1ll * p[x] * l[x], 1ll * (tick[x] + l[x] + y) * (tick[x] + l[x] + y + 1)}, x};
}

db f(int x) {
    return (db)p[x] * (tick[x]) / (tick[x] + l[x]);
}

int modify(int x, int a) {
    if(x == -1) {
        if(a == 1 && !out.empty()) x = out.rbegin() -> y;
        if(a == -1 && !in.empty()) x = in.begin() -> y;
    }
    if(x == -1) return 0;
    if(tick[x] + a < 0 || tick[x] + a > l[x]) return 0;
    if(tick[x] > 0) in.erase(f(x, -1));
    if(tick[x] + 1 <= l[x]) out.erase(f(x, 0));
    sum -= f(x);
    cnt += a;
    tick[x] += a;
    sum += f(x);
    if(tick[x] > 0) in.insert(f(x, -1));
    if(tick[x] + 1 <= l[x]) out.insert(f(x, 0));
    assert(tick[x] <= l[x]);
    return 1;
}

void change(int x, int a) {
    if(tick[x] > 0) in.erase(f(x, -1));
    if(tick[x] + 1 <= l[x]) out.erase(f(x, 0));
    sum -= f(x);
    l[x] += a;
    sum += f(x);
    if(tick[x] > 0) in.insert(f(x, -1));
    if(tick[x] + 1 <= l[x]) out.insert(f(x, 0));
    assert(tick[x] <= l[x]);
    return;
}

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout.precision(20), cout << fixed;
    cin >> n >> t >> q;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> l[i];
    for(int i = 1; i <= n; i++) {
        out.insert(f(i, 0));
    }
    for(int i = 1; i <= t; i++) modify(-1, 1);
    for(int i = 1; i <= q; i++) {
        int opt, r;
        cin >> opt >> r;
        if(opt == 1) {
            change(r, 1);
        } else {
            modify(r, -1);
            change(r, -1);
        }
        while(cnt < t && modify(-1, 1));
        while(cnt > t && modify(-1, -1));
        while(!in.empty() && !out.empty()) {
            if(in.begin() -> x < out.rbegin() -> x) {
                modify(-1, -1);
                modify(-1, 1);
            } else {
                break;
            }
        }
        cout << sum << endl;
    }
    return 0;
}