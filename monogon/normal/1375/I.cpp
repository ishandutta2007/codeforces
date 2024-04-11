
// If you copy paste my solution I will murder you in your sleep.

#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

struct quat {
    long double a, b, c, d;
    quat(long double a = 0, long double b = 0, long double c = 0, long double d = 0): a(a), b(b), c(c), d(d) {}
    quat operator+(const quat &o) const {
        return quat(a + o.a, b + o.b, c + o.c, d + o.d);
    }
    quat operator-(const quat &o) const {
        return quat(a - o.a, b - o.b, c - o.c, d - o.d);
    }
    quat operator*(const quat &o) const {
        return quat(
            a * o.a - b * o.b - c * o.c - d * o.d,
            a * o.b + b * o.a + c * o.d - d * o.c,
            a * o.c - b * o.d + c * o.a + d * o.b,
            a * o.d + b * o.c - c * o.b + d * o.a
        );
    }
    quat operator*(const long double s) const {
        return quat(s * a, s * b, s * c, s * d);
    }
    quat conj() const {
        return quat(a, -b, -c, -d);
    }
    long double norm() const {
        return a * a + b * b + c * c + d * d;
    }
    quat inv() const {
        return conj() * (1.0 / norm());
    }
};

quat round(quat q) {
    quat q1(roundl(q.a), roundl(q.b), roundl(q.c), roundl(q.d));
    quat q2(0.5 + roundl(q.a - 0.5), 0.5 + roundl(q.b - 0.5), 0.5 + roundl(q.c - 0.5), 0.5 + roundl(q.d - 0.5));
    return ((q1 - q).norm() < (q2 - q).norm() ? q1 : q2);
}

pair<quat, quat> div(quat a, quat b) {
    quat q = round(b.inv() * a);
    return {q, a - b * q};
}

const long double EPS = 1e-9;

quat gcd(quat a, quat b) {
    while(b.norm() > EPS) {
        quat r = div(a, b).second;
        a = b;
        b = r;
    }
    return a;
}

const int N = 1e4 + 5;
int n;
quat q[N];
ll x[N], y[N], z[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll gcdcoord = 0;
    rep(i, 0, n) {
        cin >> x[i] >> y[i] >> z[i];
        gcdcoord = gcd(gcd(gcdcoord, abs(x[i])), gcd(abs(y[i]), abs(z[i])));
    }
    quat g;
    rep(i, 0, n) {
        q[i] = quat(0, x[i] / gcdcoord, y[i] / gcdcoord, z[i] / gcdcoord);
        g = gcd(g, q[i]);
    }
    ll gnorm = roundl(g.norm());
    vector<ll> div;
    for(ll i = 1; i * i <= gnorm; i++) {
        if(gnorm % i == 0) {
            div.push_back(i);
            if(i * i != gnorm) {
                div.push_back(gnorm / i);
            }
        }
    }
    sort(div.rbegin(), div.rend());
    for(ll d : div) {
        quat Q = gcd(g, quat(d));
        quat Qconj = Q.conj();
        ll r = roundl(Q.norm());
        if(r != d) continue;
        quat Qprime = Q * (1.0 / r);
        quat Qprimeconj = Qconj * (1.0 / r);
        bool flag = true;
        rep(i, 0, n) {
            quat v = Qprimeconj * q[i] * Qprime;
            if(abs(roundl(v.b) - v.b) > EPS || abs(roundl(v.c) - v.c) > EPS || abs(roundl(v.d) - v.d) > EPS) {
                flag = false;
                break;
            }
        }
        if(flag) {
            quat u1 = Q * quat(0, 1, 0, 0) * Qconj;
            quat u2 = Q * quat(0, 0, 1, 0) * Qconj;
            quat u3 = Q * quat(0, 0, 0, 1) * Qconj;
            cout << (ll) (gcdcoord * gcdcoord * r * r) << '\n';
            for(quat u : {u1, u2, u3}) {
                cout << (ll) (gcdcoord * roundl(u.b)) << ' ' << (ll) (gcdcoord * roundl(u.c)) << ' ' << (ll) (gcdcoord * roundl(u.d)) << '\n';
            }
            return 0;
        }
    }
    assert(false);
}