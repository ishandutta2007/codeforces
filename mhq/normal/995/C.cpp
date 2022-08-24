#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 100;
const ll LIM = 4 * (ll)1e12;
int n;
int sgn[maxN];
struct pt{
    int x, y;
    int id;
    void operator = (const pt& t){
        x = t.x;
        y = t.y;
        id = t.id;
    }
    pt neg() {
        pt t;
        t.x = -x;
        t.y = -y;
        t.id = id;
        return t;
    }
};
vector < pt > t;
random_device rd;
mt19937 g(rd());
ll val(int x, int y) {
    return (1LL * x * x + 1LL * y * y);
}
bool ok(pt x, pt y) {
    int xx = x.x + y.x;
    int yy = x.y + y.y;
    if (1LL * xx * xx + 1LL * yy * yy <= 1LL * 1000 * 1000 * 1000 * 1000) return true;
    return false;
}
bool okk(pt x, pt y) {
    int xx = x.x + y.x;
    int yy = x.y + y.y;
    if (1LL * xx * xx + 1LL * yy * yy <= (ll)(1LL * 2100 * 1000 * 1000 * 1000)) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        pt q;
        cin >> q.x >> q.y;
        q.id = i;
        t.push_back(q);
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    int cop = n;
    vector < pt > f1, f2;
    f1.push_back(t.back());
    t.pop_back();
    f2.push_back(t.back());
    t.pop_back();
    pt resA = f1[0];
    pt resB = f2[0];
    sgn[n] = 1;
    sgn[n - 1] = 1;
    n -= 2;
    while (n > 0) {
        pt p = t.back();
        t.pop_back();
        if (ok(p, resA)) {
            f1.push_back(p);
            sgn[p.id] = 1;
            resA.x += p.x;
            resA.y += p.y;
            n--;
            continue;
        }
        if (ok(p.neg(), resA)) {
            f1.push_back(p);
            resA.x -= p.x;
            resA.y -= p.y;
            sgn[p.id] = -1;
            n--;
            continue;
        }
        if (ok(p, resB)) {
            f2.push_back(p);
            sgn[p.id] = 1;
            resB.x += p.x;
            resB.y += p.y;
            n--;
            continue;
        }
        if (ok(p.neg(), resB)) {
            resB.x -= p.x;
            resB.y -= p.y;
            sgn[p.id] = -1;
            f2.push_back(p);
            n--;
            continue;
        }
        if (ok(resA, resB)) {
            resA.x += resB.x;
            resA.y += resB.y;
            for (int i = 0; i < f2.size(); i++) f1.push_back(f2[i]);
        }
        else {
            if (!ok(resA, resB.neg())) {
                assert(0);
            }
            resA.x -= resB.x;
            resA.y -= resB.y;
            for (int i = 0; i < f2.size(); i++) {
                f1.push_back(f2[i]);
                sgn[f2[i].id] *= -1;
            }
        }
        f2.clear();
        resB.x = p.x;
        resB.y = p.y;
        sgn[p.id] = 1;
        f2.push_back(p);
        n--;
    }
    if (okk(resA, resB)) {
    }
    else {
        for (int i = 0; i < f2.size(); i++) sgn[f2[i].id] *= -1;
    }
    for (int i = 1; i <= cop; i++) cout << sgn[i] << " ";
    return 0;
}