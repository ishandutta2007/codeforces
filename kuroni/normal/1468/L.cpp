#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

typedef unsigned long long ull;
typedef long long ll;

int n, k;
long long a[N];
bool chk[N];
map<ull, int> cnt;
vector<ull> val, fct[N];
map<ull, vector<long long>> ma;

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}

bool check(int i) {
    for (ull v : fct[i]) {
        if (!binary_search(val.begin(), val.end(), v)) {
            return false;
        }
    }
    return true;
}

void print_even() {
    for (int i = 0; i < k / 2; i++) {
        auto [_, ve] = *ma.begin(); ma.erase(ma.begin());
        for (long long v : ve) {
            cout << v << " ";
        }
    }
}

void solve_small() {
    vector<long long> ans;
    for (int i = 1; i <= n; i++) {
        if (fct[i].size() == 1 && check(i) && ma[fct[i][0]].size() < 2) {
            ans.push_back(a[i]);
            ma[fct[i][0]].push_back(a[i]);
            chk[i] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!chk[i] && check(i) && ans.size() < k) {
            ans.push_back(a[i]);
        }
    }
    if (ans.size() < k) {
        cout << 0;
    } else {
        for (long long v : ans) {
            cout << v << " ";
        }
    }
}

void solve_big() {
    for (int i = 1; i <= n; i++) {
        if (fct[i].size() == 1 && check(i) && ma[fct[i][0]].size() < 2) {
            ma[fct[i][0]].push_back(a[i]);
            chk[i] = true;
        }
    }
    if (k % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            if (check(i) && 2 * fct[i].size() <= k && !chk[i]) {
                cout << a[i] << " "; k--;
                for (ull v : fct[i]) {
                    vector<long long> ve = ma[v];
                    k -= 2; ma.erase(ma.find(v));
                    for (long long v : ve) {
                        cout << v << " ";
                    }
                }
                print_even();
                return;
            }
        }
        cout << 0;
        return;
    } else {
        print_even();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    if (k == 1) {
        return cout << 0, 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fct[i] = factor(a[i]);
        sort(fct[i].begin(), fct[i].end());
        fct[i].erase(unique(fct[i].begin(), fct[i].end()), fct[i].end());
        if (fct[i].size() == 1) {
            cnt[fct[i][0]]++;
        }
    }
    for (auto [pr, c] : cnt) {
        if (c >= 2) {
            val.push_back(pr);
        }
    }
    if (2 * val.size() <= k) {
        solve_small();
    } else {
        solve_big();
    }
}