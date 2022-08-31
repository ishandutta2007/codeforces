#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
int n, m;
ull A, B, C;
const int maxN = 2 * (int)1e5 + 100;
vector < int > g[maxN];
ull pref[maxN];
ull get0(int l, int r) {
    if (r < 0) return 0;
    return r - l + 1;
}
ull get1(int l, int r) {
    if (r < 0) return 0;
    if (l == 0) return pref[r];
    else return pref[r] - pref[l - 1];
}
ull count0() {
    ull ans = 0;
    for (int i = 0; i < n; i++) {
        ans += B * i * get0(0, i - 1) * get0(i + 1, n - 1);
        ans += A * get1(0, i - 1) * get0(i + 1, n - 1);
        ans += C * get0(0, i - 1) * get1(i + 1, n - 1);
    }
    return ans;
}
vector < pair < int, int > > ed;
ull count1() {
    ull ans = 0;
    for (auto it : ed) {
        int from = it.first;
        int to = it.second;
        ans += A * from * (get0(from + 1, n - 1) - 1);
        ans += B * from * get0(0, from - 1);
        ans += C * to * (get0(0, to - 1) - 1);
        ans += B * to * get0(to + 1, n - 1);
        ans += A * get1(0, from - 1);
        ans += B * get1(from + 1, to - 1);
        ans += C * get1(to + 1, n - 1);
    }
    return ans;
}
ull C2(ull x) {
    return (x * (x - 1)) / 2;
}
ull count2() {
    ull ans = 0;
    for (int i = 0; i < n; i++) {
        vector < int > smaller, greater;
        for (int v : g[i]) {
            if (v < i) smaller.push_back(v);
            else greater.push_back(v);
        }
        sort(smaller.begin(), smaller.end());
        sort(greater.begin(), greater.end());
        ans += B * i * (ull)smaller.size() * greater.size();
        ans += A * i * C2(greater.size());
        ans += C * i * C2(smaller.size());
        for (int j = 0; j < smaller.size(); j++) {
            ans += A * (ull)smaller[j] * (greater.size() + smaller.size() - j - 1);
            ans += B * (ull)smaller[j] * j;
        }
        for (int j = 0; j < greater.size(); j++) {
            ans += B * (ull)greater[j] * (greater.size() - j - 1);
            ans += C * (ull)greater[j] * (smaller.size() + j);
        }
    }
    return ans;
}
bool hs[maxN];
int ord[maxN];
vector < int > gr[maxN];
ull count3() {
    ull ans = 0;
    vector < int > by_deg;
    for (int i = 0; i < n; i++) {
        by_deg.emplace_back(i);
    }
    sort(by_deg.begin(), by_deg.end(), [&](int i, int j) {
        return g[i].size() < g[j].size();
    });
    for (int i = 0; i < n; i++) {
        ord[by_deg[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int v : g[i]) {
            if (ord[i] < ord[v]) gr[i].push_back(v);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int p : gr[i]) {
            for (int u : gr[p]) {
                hs[u] = true;
            }
            for (int t : gr[i]) {
                if (hs[t]) {
                    int c0 = i; int c1 = p; int c2 = t;
                    if (c0 > c1) swap(c0, c1);
                    if (c0 > c2) swap(c0, c2);
                    if (c1 > c2) swap(c1, c2);
                    ans += A * c0 + B * c1 + C * c2;
                }
            }
            for (int u : gr[p]) {
                hs[u] = false;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cin >> A >> B >> C;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        if (a > b) swap(a, b);
        ed.emplace_back(a, b);
    }
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + i;
    }
    ull f0 = count0();
    ull f1 = count1();
    ull f2 = count2();
    ull f3 = count3();
    cout << f0 - f1 + f2 - f3;
    return 0;
}