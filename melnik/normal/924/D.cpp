// In the name of god
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <ctime>
#include <queue>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int x[maxn], v[maxn];



struct Frac {
    ll p, q;
    Frac() {p = 0, q = 1;}
    Frac(ll p, ll q) : p(p), q(q) {
        norm();
    }

    void norm() {
        if (q < 0) p = -p, q = -q;
        if (p == 0) q = 1;
        // ret  urn;
        // ll g = gcd(abs(p), q);
        // p /= g;
        // q /= g;
    }

    Frac& operator+=(const Frac& b) {
        p = p * b.q + q * b.p;
        q = q * b.q;
        norm();
        return *this;
    }

    friend Frac operator+(Frac a, const Frac& b) {
        a += b;
        return a;
    }

    Frac& operator*=(const Frac& b) {
        p = p * b.p;
        q = q * b.q;
        norm();
        return *this;
    }

    friend Frac operator*(Frac a, const Frac& b) {
        a *= b;
        return a;
    }

    Frac& operator-=(const Frac& b) {
        p = p * b.q - q * b.p;
        q = q * b.q;
        norm();
        return *this;                
    }

    friend Frac operator-(Frac a, const Frac& b) {
        a -= b;
        return a;
    }

    Frac& operator/=(const Frac& b) {
        p = p * b.q;
        q = q * b.p;
        norm();
        return *this;
    }

    friend Frac operator/(Frac a, const Frac& b) {
        a /= b;
        return a;
    }

    bool operator < (const Frac & T) const {
        return p * T.q < T.p * q;
    }

    bool operator <= (const Frac & T) const {
        return p * T.q <= T.p * q;
    }
};

std::ostream& operator<<(std::ostream& out, const Frac& f) {
   return out << f.p << '/' << f.q;
}

vector<Frac> szh(vector<Frac> mda) {
    sort(mda.begin(), mda.end());
    vector<Frac> ans;
    for (int i = 0; i < mda.size(); i++) {
        if (ans.empty() || ans.back() < mda[i]) {
            ans.pb(mda[i]);
        }
    }
    return ans;
}

#define all(x) (x).begin(),(x).end()

int tree[maxn];

int sum(int r) {
    r++;
    int ans = 0;
    while (r > 0) {
        ans += tree[r];
        r -= r & -r;
    }
    return ans;
}

void add(int pos ){
    pos += 1;
    while (pos < maxn) {
        tree[pos] += 1;
        pos += pos & -pos;
    }
}

int main() {
    int n, w;
    
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);

    cin >> n >> w;

    vector<pair<Frac, Frac> > tmp;
    vector<Frac> L, R;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
        
        Frac l = Frac(abs(x[i]), abs(v[i] - w));
        Frac r = Frac(abs(x[i]), abs(v[i] + w));

        tmp.pb(mp(l, r));
        L.pb(l);
        R.pb(r);
    }

    L = szh(L);
    R = szh(R);

    vector<pair<int, int> > cur;
    for (int i = 0; i < n; i++) {
        cur.push_back(make_pair(lower_bound(all(L), tmp[i].f) - L.begin(), -(lower_bound(all(R), tmp[i].s) - R.begin())));
        // cur.back().s *= -1;
    }

    sort(all(cur));

    ll ans = 0;

    for (int i = 0; i < cur.size(); i++) {
        cur[i].s *= -1;
        ans += i - sum(cur[i].s - 1); // maybe -1
        add(cur[i].s);
    }

    cout << ans;
    return 0;
}