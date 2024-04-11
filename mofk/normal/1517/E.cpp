#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long solve(const vector<long long> &a, long long tar) {
    if (a.empty()) return (tar >= 0);
    if (tar < 0 || a[0] == -1) return 0;
    long long ret = 0;
    int n = a.size();
    vector<long long> s2(n);
    s2[0] = a[0];
    s2[1] = a[1];
    for (int i = 2; i < n; ++i) s2[i] = s2[i-2] + a[i];
    long long sc = 0;
    for (int i = 0; i < n; ++i) {
        if (tar < sc) break;
        long long lim = tar - sc;
        if (i) lim += s2[i-1];
        int l = 0, r = n;
        while (l < r) {
            int m = l + r + 1 >> 1;
            if (i + 2 * m - 1 < n && s2[i + 2*m - 1] <= lim) l = m;
            else r = m - 1;
        }
        ret += l + 1;
        sc += a[i];
    }
    if (sc <= tar) ++ret;
    return ret;
}

vector<long long> subv(const vector<long long> &v, int l, int r) {
    if (l > r + 1) return vector<long long>(1, -1);
    vector<long long> a(v.begin() + l, v.begin() + r + 1);
    return a;
}

int buf(vector<long long> a) {
    int n = a.size() - 1;
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> c, p;
        for (int j = 0; j < n; ++j) if (i >> j & 1) c.push_back(j + 1); else p.push_back(j + 1);
        int bad = 0;
        for (int j = 0; j + 2 < c.size(); ++j) if (c[j+1] - c[j] > c[j+2] - c[j+1]) bad = 1;
        for (int j = 0; j + 2 < p.size(); ++j) if (p[j+1] - p[j] < p[j+2] - p[j+1]) bad = 1;
        if (!bad) {
            long long sc = 0, sp = 0;
            for (auto x: c) sc += a[x];
            for (auto x: p) sp += a[x];
            if (sc < sp) {
                ++ans;
            }
        }
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1, 0);
        vector<long long> s(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i];
        long long sum = s[n];

        if (n <= 7) {
            cout << buf(a) << endl;
            continue;
        }

        long long ans = 0;

        {
            //PP...CC...
            for (int i = 1; i <= n; ++i) if (2 * s[i] > sum) ++ans;
            long long s0 = 0, s1 = 0;
            for (int i = 1; i <= n; ++i) if (i & 1) s0 += a[i]; else s1 += a[i];
            if (s0 != s1) ++ans;
        }

        {
            //no PP
            long long sp = a[n];
            if (2 * (a[1] + a[n]) > sum) ++ans;
            for (int i = n - 1; i >= 3; --i) {
                sp = (sum - s[i-1]) - sp;
                if (sp * 2 > sum) ++ans;
                if (i > 3 && 2 * (sp + a[1]) > sum) ++ans;
            }
        }

        {
            //no CC
            long long sc = a[1];
            if (2 * a[1] < sum) ++ans;
            if (2 * (a[1] + a[n]) < sum) ++ans;
            for (int i = 2; i <= n - 2; ++i) {
                sc = s[i] - sc;
                if (sc * 2 < sum) ++ans;
                if (i < n - 2 && 2 * (sc + a[n]) < sum) ++ans;
            }
        }

        {
            long long tar = (sum - 1) / 2;
            ans += solve(subv(a, 3, n - 2), tar - a[1] - a[2]);
            ans += solve(subv(a, 4, n - 2), tar - a[2] - a[3]);
            ans += solve(subv(a, 3, n - 3), tar - a[1] - a[2] - a[n]);
            ans += solve(subv(a, 4, n - 3), tar - a[2] - a[3] - a[n]);
        }

        cout << ans % mod << endl;
    }
    return 0;
}