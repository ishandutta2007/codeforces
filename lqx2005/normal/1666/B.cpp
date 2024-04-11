#include <bits/stdc++.h>
#define trace(x) cout << #x <<" = " << x << endl
#define _ << " " <<
#define sz(a) int((a).size())
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10, M = 5;
int t, q, arr[M], c[M];
db p[M], sumc[N], a[N];
db sqsum = 0, nowc = 0, suma = 0, sumans = 0, sump = 0;
int tot = 0;
tuple<db, db, db, db, db, db> cur[N * 2];
vector<tuple<db, db, db>> s[N];
pair<ll, int> que[N];
db ans[N];
db calc(db x) {
    return suma + sqsum / sqrt(x) - nowc;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout << fixed;
    cin >> t >> q;
    for(int i = 1; i <= t; i++) {
        int n;
        ll sc = 0, sp = 0;
        cin >> n;
        for(int j = 0; j < n; j++) cin >> c[j], sc += c[j];
        for(int j = 0; j < n; j++) cin >> arr[j], sp += arr[j];
        for(int j = 0; j < n; j++) p[j] = 1. * arr[j] / sp;
        sumc[i] = sc, sc = 0;
        for(int j = 0; j < n; j++) {
            db d = c[j] / p[j] - sumc[i];
            if(d > 0) s[i].emplace_back(d, c[j], p[j]), sump += p[j], sc += c[j];
        }
        sort(s[i].begin(), s[i].end());
        db pre = 0;
        sumans += sc / sumc[i];
        for(auto [d, c, p] : s[i]) {
            db dl = sc / (sumc[i] + pre) / (sumc[i] + pre);
            db dr = sc / (sumc[i] + d) / (sumc[i] + d);
            cur[++tot] = {dl, sqrt(sc), sumc[i], -pre, - sc / (sumc[i] + pre), 0};
            cur[++tot] = {dr, -sqrt(sc), -sumc[i], d, (sc - c) / (sumc[i] + d), -p};
            sc -= c, pre = d;
        }
    }
    sort(cur + 1, cur + tot + 1, greater<tuple<db, db, db, db, db, db>>());
    for(int i = 1; i <= q; i++) cin >> que[i].x, que[i].y = i;
    sort(que + 1, que + q + 1);
    int lst = 0;
    for(int i = 1; i <= q; i++) {
        auto [x, id] = que[i];
        while(lst + 1 <= tot && calc(get<0>(cur[lst + 1])) <= x) {
            auto [x, a, b, c, d, e] = cur[lst + 1];
            sqsum += a, nowc += b, suma += c, sumans += d, sump += e;
            lst++;
        }
        if(lst == tot) ans[id] = 0;
        else {
            db v = sqsum / (x - suma + nowc);
            ans[id] = (sumans + sqsum * v - sump) * 2;
        }
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << endl;
    return 0;
}