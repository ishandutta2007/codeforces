
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct perm {
    vi p;
    perm(int k) {
        p.resize(k);
        rep(i, 0, k) p[i] = i;
    }
    void swop(int i, int j) {
        swap(p[i], p[j]);
    }
    perm operator*(const perm &o) const {
        perm ans(sz(p));
        rep(i, 0, sz(p)) ans.p[i] = p[o.p[i]];
        return ans;
    }
    int apply(const int mask) const {
        int mask2 = 0;
        int k = sz(p);
        rep(i, 0, k) {
            if(mask >> i & 1) {
                mask2 ^= (1 << p[i]);
            }
        }
        return mask2;
    }
};

int getmask(const string &s) {
    int k = s.length();
    int mask = 0;
    rep(i, 0, k) {
        if(s[i] == '1') {
            mask ^= (1 << i);
        }
    }
    return mask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    string ss, tt;
    cin >> ss >> tt;
    int s = getmask(ss);
    int t = getmask(tt);
    int pie1 = 0, pie2 = 0;
    for(char c : ss) if(c == '1') pie1++;
    for(char c : tt) if(c == '1') pie2++;
    perm P(k);
    vi a(n + 1), b(n + 1);
    rep(i, 0, n) {
        a[i] = P.apply(s);
        b[i] = P.apply(t);
        int u, v;
        cin >> u >> v;
        u--; v--;
        perm S(k);
        S.swop(u, v);
        P = P * S;
    }
    a[n] = P.apply(s);
    b[n] = P.apply(t);
    vi mi(1 << k, n + 1), mx(1 << k, -1);
    rep(i, 0, n + 1) {
        mi[a[i]] = min(mi[a[i]], i);
        mx[b[i]] = max(mx[b[i]], i);
    }

    int best = -1, l = -1, r = -1;

    rep(mask, 0, 1 << k) {
        int cnt = 0;
        rep(i, 0, 20) {
            if(mask >> i & 1) {
                mi[mask] = min(mi[mask], mi[mask ^ (1 << i)]);
                mx[mask] = max(mx[mask], mx[mask ^ (1 << i)]);
                cnt++;
            }
        }
        cnt = k - cnt;
        if(cnt > best && mx[mask] - mi[mask] >= m) {
            best = cnt;
            l = mi[mask] + 1;
            r = mx[mask];
        }
    }
    cout << pie1 + pie2 + 2 * best - k << '\n' << l << ' ' << r << '\n';
}