
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    suffix_array SA(s);
    vi p = SA.p;

    s += '$';

    auto cmp = [&](const string &t, int idx) -> int {
        idx = p[idx];
        rep(i, 0, (int) t.length()) {
            if(t[i] != s[idx + i]) {
                return (t[i] < s[idx + i] ? -1 : 1);
            }
        }
        return 0;
    };
    auto get_lower = [&](const string &t) -> int {
        int L = 0, R = n + 1;
        while(L < R) {
            int m = (L + R) / 2;
            if(cmp(t, m) > 0) {
                L = m + 1;
            }else {
                R = m;
            }
        }
        return L;
    };
    auto get_upper = [&](const string &t) -> int {
        int L = 0, R = n + 1;
        while(L < R) {
            int m = (L + R) / 2;
            if(cmp(t, m) >= 0) {
                L = m + 1;
            }else {
                R = m;
            }
        }
        return L;
    };
    // cout << "SUFFIX ARRAY: ";
    // for(int x : p) cout << x << ' ';
    // cout << '\n';
    
    int q;
    cin >> q;
    vi ve;

    while(q--) {
        int k; string t;
        cin >> k >> t;
        int L = get_lower(t), R = get_upper(t);
        // cout << L << ' ' << R << '\n';
        if(R - L < k) {
            cout << -1 << '\n';
            continue;
        }
        ve.clear();
        rep(i, L, R) {
            ve.push_back(p[i]);
        }
        sort(all(ve));
        int ans = INT_MAX;
        rep(i, 0, sz(ve) - k + 1) {
            ans = min(ans, ve[i + k - 1] - ve[i]);
        }
        cout << ans + t.length() << '\n';
    }
}