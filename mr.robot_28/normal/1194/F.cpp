#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    fore(i, 0, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out;
}

const int MOD = int(1e9) + 7;

inline int norm(int a) {
    if(a >= MOD) a -= MOD;
    if(a < 0) a += MOD;
    return a;
}
inline int mul(int a, int b) {
    return int(a * 1ll * b % MOD);
}
inline int binPow(int a, int k) {
    int ans = 1;
    while(k > 0) {
        if(k & 1) ans = mul(ans, a);
        a = mul(a, a);
        k >>= 1;
    }
    return ans;
}
inline int inv(int a) {
    return binPow(a, MOD - 2);
}

int n;
li T;
vector<li> t;

inline bool read() {
    if(!(cin >> n >> T))
        return false;
    t.resize(n);
    fore(i, 0, n)
        cin >> t[i];
    return true;
}

vector<int> f, inf;

int C(int n, li k) {
    if(k > n || k < 0)
        return 0;
    return mul(f[n], mul(inf[k], inf[n - k]));
}

inline void solve() {
    f.resize(n + 5);
    inf.resize(n + 5);
    f[0] = inf[0] = 1;
    fore(i, 1, sz(f)) {
        f[i] = mul(i, f[i - 1]);
        inf[i] = mul(inf[i - 1], inv(i));
    }

    int sumC = 1;
    li bd = T;
    int pw2 = 1, i2 = (MOD + 1) / 2;

    vector<int> p(n + 1, 0);
    fore(i, 0, n) {
        pw2 = mul(pw2, i2);

        sumC = norm(mul(2, sumC) - C(i, bd));
        li need = t[i];
        if(bd > i + 1) {
            li sub = min(bd - i - 1, need);
            bd -= sub, need -= sub;
        }
        li rem = min(bd + 1, need);
        fore(k, 0, rem)
            sumC = norm(sumC - C(i + 1, bd - k));
        bd -= rem;

        p[i] = mul(sumC, pw2);
    }

    int ans = int(accumulate(p.begin(), p.end(), 0ll) % MOD);
    cout << ans << endl;
//    cerr << mul(ans, binPow(2, n)) << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    cout << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}