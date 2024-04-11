#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MX = 2100000;

int bb[MX];
vector<int> pr;

void rn(ll x, map<ll, int> &mm) {
    while (x != 1) {
        ll y = bb[x];
        ++mm[y];
        x /= y;
    }
}



map<ll, int> mn;
map<ll, int> mm;
map<ll, int> ms;
vector<pair<ll, int>> vm;
vector<pair<ll, int>> vn;
vector<pair<ll, int>> vs;
vector<ll> gv;
vector<ll> v1;
vector<ll> v2;

void run(vector<ll> &vv, int l, int r, ll now) {
    if (l == r) {
        vv.push_back(now);
        return;
    }
    for (int i = 0; i < vs[l].second; ++i) {
        run(vv, l + 1, r, now);
        now *= vs[l].first;
    }
    run(vv, l + 1, r, now);
}

ll run2(int x, ll now, int c) {
    if (x == gv.size()) {
        if (c)
            return -now;
        else
            return now;
    }
    return run2(x + 1, now, c) + run2(x + 1, now / gv[x], c ^ 1);
}

void solve() {
    ll n1, n2, n3;
    ll m1, m2, m3;
    ll s1, s2, s3;

    cin >> n1 >> n2 >> n3;
    cin >> m1 >> m2 >> m3;
    cin >> s1 >> s2 >> s3;
    s1 *= 2;
    mn.clear();
    mm.clear();
    ms.clear();
    rn(n1, mn);
    rn(n2, mn);
    rn(n3, mn);
    rn(m1, mm);
    rn(m2, mm);
    rn(m3, mm);
    rn(s1, ms);
    rn(s2, ms);
    rn(s3, ms);
    vn.clear();
    vm.clear();
    vs.clear();
    for (auto i: mm)
        vm.push_back(i);
    for (auto i: mn)
        vn.push_back(i);
    for (auto i: ms)
        vs.push_back(i);
    ll n = n1 * n2 * n3;
    ll m = m1 * m2 * m3;
    ll ans = 0;
    v1.clear();
    v2.clear();
    int g = vs.size() / 2;
    run(v1, 0, g, 1);
    run(v2, g, vs.size(), 1);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int now = v1.size() - 1;
    for (int i = 0; i < v2.size(); ++i) {
        while (now >= 0 && v1[now] * v2[i] > n)
            --now;
        ans += now + 1;
    }
    gv.clear();
    for (auto i: mn) {
        if (i.second > ms[i.first]) {
            ll go = 1;
            int gg = ms[i.first] + 1;
            for (int j = 0; j < gg; ++j)
                go *= i.first;
            gv.push_back(go);
        }
    }
    ans += run2(0, m, 0);
    cout << ans << "\n";
}


void init() {
    for (int i = 0; i < MX; ++i)
        bb[i] = i;
    for (int i = 2; i < MX; ++i) {
        if (bb[i] == i)
            pr.push_back(i);
        for (int j: pr) {
            if (bb[i] < j || j * i >= MX)
                break;
            bb[i * j] = j;
        }
    }
}

int main() {
    init();
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; ++i)
        solve();
    return 0;
}