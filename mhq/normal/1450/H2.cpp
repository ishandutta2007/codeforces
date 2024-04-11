#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1 << 20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

const int maxN = 9 * (int) 1e5 + 100;

int fact[maxN], invfact[maxN], inv[maxN];

struct query {
    int L, R, fl, id, coef;

    query(int _L, int _R, int _fl, int _id, int _coef) : L(_L), R(_R), fl(_fl), id(_id), coef(_coef) {}
};

const int BLOCK = 500;

bool cmp(query &a, query &b) {
    return make_pair(a.L / BLOCK, a.R) < make_pair(b.L / BLOCK, b.R);
}

int L, R, res;

int cnk(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}

void incL() {
    L++;
    res = sum(res, cnk(R, L));
}
void decL() {
    res = sub(res, cnk(R, L));
    L--;
}
void incR() {
    res = sum(res, res);
    res = sub(res, cnk(R, L));
    R++;
}
const int inv2 = (mod + 1) / 2;
void decR() {
    R--;
    res = sum(res, cnk(R, L));
    res = mult(res, inv2);
}



int n, m;


void init() {
    inv[1] = invfact[1] = invfact[0] = fact[0] = fact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}


const int maxQ = 3e5 + 10;
int f[2] = {0, 0};
int q[2] = {0, 0};
vector<query> all;
int F[2 * maxQ];
//dev 2

void calc(int id) {
    int A = f[0];
    int B = f[1];
    int X = q[0];
    int Y = q[1];
    all.emplace_back(X + Y, X + Y, (A + B) % 2, id + maxQ, 1);

    all.emplace_back(min(X + Y, X + A - B), X + Y, (A + B + X) % 2, id, sub(A, B));
    all.emplace_back(min(X + Y - 1, X + A - B), X + Y - 1, (A + B + X) % 2, id, X);
    all.emplace_back(min(X + Y - 1, X + A - B - 1), X + Y - 1, (A + B + X + 1) % 2, id, sub(0, Y));





    all.emplace_back(min(B - A - 1 + Y, X + Y), X + Y, (A + B + Y) % 2, id, sub(B, A));
    all.emplace_back(min(B - A - 1 + Y, X + Y - 1), X + Y - 1, (A + B + Y) % 2, id, Y);
    all.emplace_back(min(B - A - 1 + Y - 1, X + Y - 1), X + Y - 1, (A + B + Y + 1) % 2, id, sub(0, X));
}

pair<int,int> get() {
    int tot_sum = res;
    int diff = 0;
    if (R == 0) {
        assert(L == 0);
        return make_pair(1, 0);
    }
    if (L % 2 == 0) {
        diff = cnk(R - 1, L);
    }
    else {
        diff = sub(0, cnk(R - 1, L));
    }
    int even = mult(inv2, sum(diff, tot_sum));
    int odd = mult(inv2, sub(tot_sum, diff));
    return make_pair(even, odd);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    init();

    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'w') {
            f[i % 2]++;
        } else if (s[i] == '?') {
            q[i % 2]++;
        }
    }
    calc(0);
    auto upd = [&](int where, int sgn) {
        if (s[where] == 'w') {
            f[where % 2] += sgn;
        }
        else if (s[where] == '?') {
            q[where % 2] += sgn;
        }
    };

    for (int i = 1; i <= m; i++) {
        int pos;
        cin >> pos;
        pos--;
        char to;
        cin >> to;
        upd(pos, -1);
        s[pos] = to;
        upd(pos, +1);
        calc(i);
    }
    sort(all.begin(), all.end(), cmp);
    L = 0;
    R = 0;
    res = 1;
    for (auto it : all) {
        if (it.L < 0) continue;
        while (R < it.R) incR();
        while (L > it.L) decL();
        while (R > it.R) decR();
        while (L < it.L) incL();
//        cout << L << " " << R << " " << res << " " << " " << endl;// p.first << " " << p.second << endl;
        pair<int,int> p = get();
        if (it.fl == 1) {
            F[it.id] = sum(F[it.id], mult(p.second, it.coef));
        }
        else {
            F[it.id] = sum(F[it.id], mult(p.first, it.coef));
        }
    }
    for (int i = 0; i <= m; i++) {
        F[i] = mult(F[i], inv2);
        cout << mult(F[i], pw(F[i + maxQ], mod - 2)) << '\n';
    }


    return 0;
}