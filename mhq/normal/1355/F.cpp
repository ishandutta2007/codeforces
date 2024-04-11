#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
vector < int > primes;
const int BUBEN = 1000;
int lp[BUBEN + 228];
const int LIM = (int)1e9;

vector < pair < int, int > > coef;
vector < vector < pair < int, int > > > all;
int X = 25252532;
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
ll ask(ll num) {
    cout << "? " << num << endl;
    assert(num <= (ll)1e18);
#ifdef DEBUG
    return gcd(num, (ll)X);
#endif
    ll resp;
    cin >> resp;
    return resp;
}
int t[10];
int CUR_LIM;
int real_divs(int X) {
    int c = 0;
    for (int i = 1; i * i <= X; i++) {
        if (X % i == 0) {
            c++;
            if (i != X / i) c++;
        }
    }

    return c;
}
const ll T = (ll)1e18;
ll F[505];
int ggg[1500];
vector < int > pri[505];
int SZ = 0;
void solve() {
    CUR_LIM = LIM;
    int dvs = 1;
    vector < int > inter;
    for (int i = 0; i <= SZ; i++) {
        ll g = ask(F[i]);
        for (int v : pri[i]) {
            if (g % v == 0) {
                inter.emplace_back(v);
            }
        }
    }
    assert(inter.size() <= 14);
    for (int i = 0; i < inter.size(); i += 2) {
        ll Q = 1;
        vector < int > c;
        if (i + 1 == inter.size()) c = {inter[i]};
        else c = {inter[i], inter[i + 1]};
        for (int v : c) {
            int M = 1;
            while (M <= LIM / v) {
                Q *= v;
                M *= v;
            }
        }
        ll g = ask(Q);
        for (int v : c) {
            int ex = 0;
            while (g % v == 0) {
                g /= v;
                CUR_LIM /= v;
                ex++;
            }
            dvs *= (ex + 1);
        }
    }
    int r = dvs;
    int p = 1;
    while (p * p * p * 4 <= LIM) p++;
    while (p <= CUR_LIM) {
        bool pr = true;
        for (int j = 2; j * j <= p; j++) {
            if (p % j == 0) {
                pr = false;
            }
        }
        if (!pr) {
            p++;
            continue;
        }
        r *= 2;
        CUR_LIM /= p;
        p++;
    }
#ifdef DEBUG
assert(dvs <= real_divs(X) && real_divs(X) <= r);
#endif
    for (int a = dvs; a <= r; a++) {
        bool ok = true;
        if (r > 2 * a && abs(r - a) > 7) {
            ok = false;
        }
        if (2 * dvs < a && abs(dvs - a) > 7) {
            ok = false;
        }
        if (ok) {
            cout << "! " << a << endl;
            return ;
        }
    }
//    assert(false);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    /*int R = 0;
    while ((R + 1) * (R + 1) * (R + 1) * (R + 1) <= LIM) R++;
    t[1] = sqrt(LIM) + 1;
    assert(t[1] * t[1] > LIM);
    t[2] = 1001;
    assert(t[2] * t[2] * t[2] > LIM);
    t[3] = R + 1;
    assert(t[3] * t[3] * t[3] * t[3] > LIM);*/
    F[SZ] = 1;
    for (int i = 2; i * i * i * 4 <= LIM; i++) {
        if (ggg[i] == 0) {
            ggg[i] = i;
            for (int j = 2 * i; j < 1500; j += i) {
                ggg[j] = i;
            }
            if (F[SZ] > T / i) {
                SZ++;
                F[SZ] = 1;
            }
            F[SZ] *= i;
            pri[SZ].emplace_back(i);
        }
    }
   /* for (int i = 2; i <= R; i++) {
        if (lp[i] == 0) {
            primes.emplace_back(i);
            int c = 1;
            int ex = 0;
            while (c <= LIM / i) {
                c *= i;
                ex++;
            }
            coef.emplace_back(ex, i);
            lp[i] = i;
            for (int j = 2 * i; j <= R; j += i) lp[j] = i;
        }
    }
    for (int a = 0; a < coef.size(); a += 2) {
        if (a + 1 == coef.size()) all.push_back({coef[a]});
        else all.push_back({coef[a], coef[a + 1]});
    }*/
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}