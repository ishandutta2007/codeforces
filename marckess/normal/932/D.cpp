#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

struct MX {
    MX *izq, *der;
    int mx;

    MX () : izq(0), der(0), mx(0) {}
    MX (MX *_i, MX *_d, int _m) : izq(_i), der(_d), mx(_m) {}
    MX (MX *_i, MX *_d) {
        izq = _i;
        der = _d;
        mx = max(izq->mx, der->mx);
    }

    void build (int i, int j) {
        if (i == j) {
            return;
        }

        int m = (i+j)/2;
        izq = new MX(0, 0, -1);
        der = new MX(0, 0, -1);
        izq->build(i, m);
        der->build(m+1, j);
    }

    MX *insert (int i, int j, int x, int val) {
        if (x < i || x > j)
            return this;

        if (i == j)
            return new MX(0, 0, val);

        int m = (i+j)/2;
        return new MX(izq->insert(i, m, x, val),
                  der->insert(m+1, j, x, val)
                );
    }

    int query (int i, int j, int x) {
        if (i == j)
            return i;

        int m = (i+j)/2;
        if (der->mx >= x)
            return der->query(m+1, j, x);
        return izq->query(i, m, x);
    }
};

struct SUM {
    SUM *izq, *der;
    ll sum;
    int cn;

    SUM () : izq(0), der(0), sum(0), cn(0) {}
    SUM (SUM *_i, SUM *_d, ll _s, int _c) : izq(_i), der(_d), sum(_s), cn(_c) {}
    SUM (SUM *_i, SUM *_d) : izq(_i), der(_d) {
        sum = izq->sum + der->sum;
        cn = izq->cn + der->cn;
    }

    void build (int i, int j) {
        if (i == j) {
            return;
        }

        int m = (i+j)/2;
        izq = new SUM();
        der = new SUM();
        izq->build(i, m);
        der->build(m+1, j);
    }

    SUM *insert (int i, int j, int x, ll val) {
        if (x < i || x > j)
            return this;

        if (i == j)
            return new SUM(0, 0, val, 1);

        int m = (i+j)/2;
        return new SUM(izq->insert(i, m, x, val),
                  der->insert(m+1, j, x, val)
                );
    }

    int query (int i, int j, ll x) {
        if (i == j) {
            if (sum <= x)
                return cn;
            return 0;
        }

        int m = (i+j)/2;
        if (der->sum <= x)
            return der->cn + izq->query(i, m, x - der->sum);
        return der->query(m+1, j, x);
    }
};

MX *mx[400000];
SUM *sum[400000];

int t, op, r, w, last = 0, n = 400003, cn = 1;
ll p, q, x;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    mx[0] = new MX();
    sum[0] = new SUM();

    mx[0]->build(1, n);
    sum[0]->build(1, n);

    mx[0] = mx[0]->insert(1, n, 1, 1e9);
    sum[0] = sum[0]->insert(1, n, 1, 2e15);

    mx[1] = mx[0]->insert(1, n, 2, 0);
    sum[1] = sum[0]->insert(1, n, 2, 0);
    
    cin >> t;
    while (t--) {
        cin >> op >> p >> q;
        if (op == 1) {
            r = p ^ last;
            w = q ^ last;
            cn++;

            int d = mx[r]->query(1, n, w) - 1;
            mx[cn] = mx[r]->insert(1, n, cn+1, w);
            sum[cn] = sum[d]->insert(1, n, cn+1, w);
        } else {
            r = p ^ last;
            x = q ^ last;
            last = sum[r]->query(1, n, x);

            cout << last << endl;
        }
    }

    return 0;
}