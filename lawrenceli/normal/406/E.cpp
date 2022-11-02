#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <map>

using namespace std;

typedef long long ll;

const int maxn = 100100;

int n, m;
vector<int> v[2];
ll ans;
int s0, s1;

ll C(int a, int b) {
    ll ret = 1;
    for (int i = a; i > a - b; i--) ret *= i;
    for (int i = 1; i <= b; i++) ret /= i;
    return ret;
}

void go(bool k) {
    int a = 0, b = 0;
    for (int i = 0; i < v[k].size(); i++) {
        if (v[k][i] == 0) a++;
        else if (v[k][i] == n) b++;
    }

    ans += C(a, 2) * b + a * C(b, 2) + a * b * (v[k].size() - a - b);
}

void calc() {
    map<int, int> f1;
    for (int i = 0; i < s1; i++) f1[v[1][i]]++;

    int cur = 0;
    for (int i = 0; i < s0; i++) {
        cur++;
        if (i == s0 - 1 || v[0][i] != v[0][i + 1]) {
            ans += (C(cur, 2) + ll(cur) * (s0 - cur) + ll(i + 1 - cur) * (s0 - 1 - i)) * f1[v[0][i]];
            cur = 0;
        }
    }

    for (auto it : f1) {
        int a = it.first, b = it.second;
        int x = lower_bound(v[0].begin(), v[0].end(), a) - v[0].begin();
        if (x < s0 && v[0][x] == a) continue;
        ans += ll(b) * x * (s0 - x);
    }
}

int ma;

void check(bool k) {
    int a = 0, b = 0;
    for (int i = 0; i < v[k].size(); i++) {
        if (v[k][i] == v[k][0]) a++;
        else if (v[k][i] == v[k].back()) b++;
    }
    if (v[k][0] == v[k].back()) ans += C(a, 3);
    else ans += ll(a) * b * (v[k].size() - a - b);
}

void go2() {
    ma = max(v[0][s0-1] - v[0][0], v[1][s1-1] - v[1][0]);
    ma = max(ma, n - min(abs(v[0][s0-1] - v[1][0]), abs(v[1][s1-1] - v[0][0])));

    for (int k = 0; k < 2; k++)
        if (v[k][v[k].size() - 1] - v[k][0] == ma)
            check(k);

    if (v[1][s1-1] < v[0][0]) swap(v[0], v[1]), swap(s0, s1);
    if (v[1][0] - v[0][s0-1] == n - ma) {
        int a = 0, b = 0;
        for (int i = 0; i < s0; i++)
            if (v[0][i] == v[0][s0-1]) a++;
        for (int i = 0; i < s1; i++)
            if (v[1][i] == v[1][0]) b++;

        ans += ll(a) * C(b, 2) + ll(b) * C(a, 2);
        ans += ll(a) * b * (m - a - b);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    if (v[0].empty()) swap(v[0], v[1]);
    s0 = v[0].size(), s1 = v[1].size();
    if (v[1].empty()) {
        if (v[0][0] == v[0][s0-1]) {
            cout << C(s0, 3) << '\n';
            return 0;
        }

        int a = 0, b = 0;
        for (int i = 0; i < s0; i++) {
            if (v[0][i] == v[0][0]) a++;
            else if (v[0][i] == v[0][s0-1]) b++;
        }

        cout << C(a, 2) * b + a * C(b, 2) + a * b * (m - a - b) << '\n';

        return 0;
    }

    for (int k = 0; k < 2; k++)
        if (v[k][0] == 0 && v[k][v[k].size() - 1] == n)
            go(k);

    calc();
    swap(v[0], v[1]), swap(s0, s1);
    calc();

    if (ans == 0) go2();

    cout << ans << '\n';
}