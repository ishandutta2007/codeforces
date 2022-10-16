#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 998244353;

int modpow(int a, int n) {
    int c = 1;

    while (n) {
        if (n & 1){
            c = 1LL * c * a % mod;
        }
        n >>= 1;
        a = 1LL * a * a % mod;
    }

    return c;
}

void add(int &a, int b){
    a += b;
    if (a >= mod)
        a -= mod;
}

void sub(int &a, int b){
    a -= b;
    if (a < 0)
        a += mod;
}

int inverse(int a){
    return modpow(a, mod - 2);
}

struct v {
    int a, b, c;

    v operator+(const v &o) const {
        int a1 = 1LL * a * o.a % mod;
        int b1 = 1LL * a * o.b % mod;
        add(b1, b);
        int c1 = 1LL * a * o.c % mod;
        add(c1, c);
        return {a1, b1, c1};
    }
};

struct segment_tree {
    vector<v> data;

    segment_tree(vector<int> p) {
        int n = p.size();
        data = vector<v>(4 * p.size());
        build(1, 0, p.size(), p);
    }

    void build(int p, int b, int e, vector<int> &proba) {
        if (b + 1 == e) {
            int x = 1;
            sub(x, proba[b]);
            data[p] = {proba[b], x, 1};
        } else {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            build(l, b, m, proba);
            build(r, m, e, proba);
            data[p] = data[l] + data[r];
        }
    }

    v query(int p, int b, int e, int x, int y) {
        if (x <= b && e <= y)
            return data[p];
        else {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;

            if (x >= m)
                return query(r, m, e, x, y);

            auto ans = query(l, b, m, x, y);
            if (m < y)
                ans = ans + query(r, m, e, x, y);

            return ans;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> proba(n + 1);
    proba[0] = 1;

    for (int i = 1; i <= n; ++i){
        int p; cin >> p;

        p = 1LL * p * inverse(100) % mod;
        proba[i] = p;
    }

    segment_tree st(proba);

    set<int> checkpoint;

    checkpoint.insert(1);
    checkpoint.insert(n + 1);

    auto E = [&](int a, int b) {
        auto ans = st.query(1, 0, n + 1, a, b);
        int B = ans.b;
        int C = ans.c;
        int SB = 1;
        sub(SB, B);
        C = 1LL * C * inverse(SB) % mod;
        return C;
    };

    int answer = E(1, n + 1);

    while (q-->0) {
        int x; cin >> x;

        if (checkpoint.find(x) == checkpoint.end()) {
            auto it = checkpoint.lower_bound(x);
            int b = *it;
            int a = *--it;
            sub(answer, E(a, b));
            add(answer, E(a, x));
            add(answer, E(x, b));
            checkpoint.insert(x);
        } else {
            auto it = checkpoint.lower_bound(x);
            int a = *--it;
            ++it;
            int b = *++it;
            sub(answer, E(a, x));
            sub(answer, E(x, b));
            add(answer, E(a, b));
            checkpoint.erase(x);
        }

        cout << answer << endl;
    }

    return 0;
}