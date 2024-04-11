#include <bits/stdc++.h>
using namespace std;

using lld = int64_t;
using pt = complex<lld>;

pair<pt,lld> calc(int n, int s) {
    int d[20], p[20];
    p[0] = 0;
    for (int i = 0; i < n; i++) {
        d[i] = (s >> i & 1 ? 1 : -1);
        p[i + 1] = p[i] + d[i];
    }
    lld xmsum = 0, ymsum = 0, msum = 0;
    for (int i = 0; i < n; i++) {
        msum += (p[i] + p[i + 1]) * 3; // 6.0
        xmsum += (p[i] * i * 6 + (p[i] + d[i] * i) * 3 + d[i] * 2); // 6.0
        ymsum += (p[i] * p[i] * 3 + d[i] * p[i] * 3 + d[i] * d[i]); // 6.0
    }
    return {pt{xmsum, ymsum}, msum};
}

bool valid(int n, int s) {
    int b = 0;
    for (int i = 0; i < n; i++) {
        if (s >> i & 1) {
            ++b;
        } else {
            --b;
        }
        if (b < 0)
            return false;
    }
    // if (b != 0) return false;
    return true;
}

string getString(int n, int s) {
    string res;
    for (int i = 0; i < n; i++) {
        if (s >> i & 1) {
            res += '(';
        } else {
            res += ')';
        }
    }
    return res;
}

namespace std {
    bool operator<(const pt &a, const pt &b) {
        if (a.real() != b.real())
            return a.real() < b.real();
        return a.imag() < b.imag();
    }
}

using llf = long double;
const llf eps = 1e-9;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    llf X, Y;
    cin >> n >> X >> Y;
    lld div = -1;
    for (int s = 1; s <= 10000; s++) {
        if (abs(round(X * s) - X * s) < s * eps && abs(round(Y * s) - Y * s) < s * eps) {
            div = s;
            break;
        }
    }
    assert (div != -1);
    pt totalcm{round(X * div), round(Y * div)};
    // cerr << "div = " << div << endl;
    const int m = n / 2;
    vector<pair<pt,int>> A[36], B[36];
    for (int s = 0; s < (1<<m); s++) {
        if (valid(m, s)) {
            int pc = __builtin_popcount(s);
            int bal = pc - (m - pc);
            auto [cm, ma] = calc(m, s);
            pt P = cm * div - totalcm * ma;
            cm.real(n * ma - cm.real());
            pt Q = cm * div - totalcm * ma;
            A[bal].emplace_back(P, s);
            B[bal].emplace_back(Q, s);
        }
    }
    const auto is0 = [](pt p) {
        return norm(p) == 0;
        return p.real() == 0 && p.imag() == 0;
    };
    for (int i = 0; i < n; i++) {
        sort(B[i].begin(), B[i].end());
        for (auto [val, msk]: A[i]) {
            auto it = lower_bound(B[i].begin(), B[i].end(), make_pair(-val, 0));
            if (it != B[i].end() && is0(val + it->first)) {
                string L = getString(m, msk);
                string R = getString(m, it->second);
                // cerr << L << ',' << R << endl;
                for (char &c: R) c = (c == '(' ? ')' : '(');
                reverse(R.begin(), R.end());
                cout << L + R << '\n';
                return 0;
            }
        }
    }
    assert (false);
    cout << "no\n";
    return 0;
}