#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 1<<16;

ll k;
int n, m, p;
int s[2*maxn];
pll v[maxn];

struct mat {
    int a[2][2];

    mat() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }

    mat(int x) {
        a[0][0] = a[1][1] = 1%p;
        a[0][1] = a[1][0] = 0;
    }

    mat(int x, int y) {
        a[0][0] = 0, a[1][0] = 1%p;
        a[0][1] = x%p, a[1][1] = y%p;
    }

    mat operator*(mat m) {
        mat ret = mat();
        for (int i=0; i<2; i++)
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++)
                    ret.a[i][k] = (ret.a[i][k]+ll(a[i][j])*m.a[j][k]%p)%p;
        return ret;
    }
};

mat t[4*maxn];

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        t[cur] = mat(s[lt], s[lt+1]);
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        t[cur] = t[2*cur] * t[2*cur+1];
    }
}

mat qry(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return mat(0);
    else if (lt >= ql && rt <= qr) return t[cur];
    else {
        int mid = (lt + rt) / 2;
        return qry(2*cur, lt, mid, ql, qr) * qry(2*cur+1, mid, rt, ql, qr);
    }
}

mat exp(mat b, ll e) {
    if (!e) return mat(0);
    if (e&1) return exp(b, e-1)*b;
    mat res = exp(b, e/2);
    return res*res;
}

mat rqry(ll lt, ll rt) {
    ll x = (rt-lt)%n;
    ll y = lt / n; 
    mat ret = qry(1, 0, 2*n, lt-y*n, lt-y*n+x);
    mat m2 = qry(1, 0, 2*n, rt%n, rt%n+n);
    return ret * exp(m2, (rt-lt)/n);
}

int main() {
    cin >> k >> p;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        s[i] %= p;
        s[i+n] = s[i];
    }
    s[2*n] = s[0];

    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> v[i].fi >> v[i].se;
        v[i].se %= p;
    }

    sort(v, v+m);

    init(1, 0, 2*n);

    mat cur = mat(0);
    ll lt = 0;
    v[m].fi = (1e18) + 5;
    for (int i=0; i<=m; i++) {
        ll x = v[i].fi, y = v[i].se;
        if (x > k) {
            cur = cur * rqry(lt, k);
            break;
        }
        if (i==0 || x != v[i-1].fi+1) {
            cur = cur * rqry(lt, x-1);
            cur = cur * mat(s[(x+n-1)%n], y);
        }

        if (x == k) break;
        
        if (x+1 != v[i+1].fi) {
            cur = cur * mat(y, s[(x+1)%n]);
        } else {
            cur = cur * mat(y, v[i+1].se);
        }

        lt = x+1;
    }

    cout << cur.a[1][0] << '\n';
}