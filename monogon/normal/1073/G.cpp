
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

struct suffix_array {
    int n;
    string s;
    vector<int> p, rank, lcp;
    suffix_array(string s) : s(s) {
        const int A = 256;
        s.push_back('$');
        n = s.length();
        int cl = 1;
        vector<int> c(n), pn(n), cn(n), cnt(max(A, n), 0);
        p.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cnt[s[i]]++;
        }
        for(int i = 1; i < A; i++) {
            cnt[i] += cnt[i - 1];
        }
        for(int i = 0; i < n; i++) {
            p[--cnt[s[i]]] = i;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(s[p[i]] != s[p[i - 1]]) {
                cl++;
            }
            c[p[i]] = cl - 1;
        }
        for(int h = 0; (1 << h) < n; h++) {
            for(int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if(pn[i] < 0) {
                    pn[i] += n;
                }
            }
            fill(cnt.begin(), cnt.begin() + cl, 0);
            for(int i = 0; i < n; i++) {
                cnt[c[pn[i]]]++;
            }
            for(int i = 1; i < cl; i++) {
                cnt[i] += cnt[i - 1];
            }
            for(int i = n - 1; i >= 0; i--) {
                p[--cnt[c[pn[i]]]] = pn[i];
            }
            cn[p[0]] = 0;
            cl = 1;
            for(int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prv = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
                if(cur != prv) {
                    cl++;
                }
                cn[p[i]] = cl - 1;
            }
            c.swap(cn);
        }
        rank.assign(n, 0);
        for(int i = 0; i < n; i++) {
            rank[p[i]] = i;
        }
        int k = 0;
        lcp.assign(n - 1, 0);
        for(int i = 0; i < n; i++) {
            if(rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while(i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            lcp[rank[i]] = k;
            if(k > 0) {
                k--;
            }
        }
    }
};

template<typename T, class Compare = std::less<T>>
struct sparse {
    vector<vector<T>> st;
    vector<int> log;
    int n;
    sparse(vector<T> a) {
        n = a.size();
        int lg = 20;
        st.assign(n, vector<T>(lg));
        for(int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for(int j = 1; j < lg; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1], Compare{});
            }
        }
        log.assign(n + 1, 0);
        log[1] = 0;
        for(int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
    }
    int getmin(int l, int r) {
        r = min(r, n - 1);
        int j = log[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j], Compare{});
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    string s;
    cin >> n >> q >> s;
    suffix_array S(s);
    sparse<int> ST(S.lcp);

    auto dnc = [&](auto dnc, int l, int r, const vector<pair<int, bool>> &v) {
        if(l == r) return 0LL;
        int m = (l + r) / 2;
        ll ans = dnc(dnc, l, m, v) + dnc(dnc, m + 1, r, v);
        ll a = 0, b = 0;
        int L = m, R = m + 1;
        if(!v[L].second) a++;
        if(v[R].second) {
            b++;
            ans += ST.getmin(v[L].first, v[R].first) * a;
        }
        while(L > l || R < r) {
            bool le = (R == r || (L > l && ST.getmin(v[L - 1].first, v[R].first) >= ST.getmin(v[L].first, v[R + 1].first)));
            if(le) L--;
            else R++;
            ll mi = ST.getmin(v[L].first, v[R].first);
            if(le && !v[L].second) {
                a++;
                ans += mi * b;
            }
            if(!le && v[R].second) {
                b++;
                ans += mi * a;
            }
        }
        return ans;
    };
    auto solve = [&](const vector<int> &a, const vector<int> &b) {
        vector<pair<int, bool>> v;
        for(int x : a) v.push_back({S.rank[x], 0});
        for(int x : b) v.push_back({S.rank[x] - 1, 1});
        sort(v.begin(), v.end());
        return dnc(dnc, 0, sz(v) - 1, v);
    };
    vi ma(n + 1);
    while(q--) {
        int k, l;
        cin >> k >> l;
        vi a(k), b(l);
        ll ans = 0;
        rep(i, 0, k) {
            cin >> a[i], a[i]--;
            ma[a[i]]++;
        }
        rep(i, 0, l) {
            cin >> b[i], b[i]--;
            ans += 1LL * ma[b[i]] * (n - b[i]);
        }
        rep(i, 0, k) ma[a[i]]--;
        cout << ans + solve(a, b) + solve(b, a) << '\n';
    }
}