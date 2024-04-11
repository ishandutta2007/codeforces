#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fit(i,c) for(decltype(c.begin()) i=c.begin();i!=c.end();++i)
#define Fid(i,c) for(decltype(c.rbegin()) i=c.rbegin();i!=c.rend();++i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

const int mod = 1000000007;

int n, D;
VI a[3030];
int p2[3030];
int F[3030][3030];
int C[3030][3030];
int G[3030];

LL PP(int x, int n) {
    if (n == 0) return 1;
    else {
        LL r = PP(x, n / 2);
        if (n % 2 == 0) return r * r % mod;
        else return r * r % mod * x % mod;
    }
}

LL CC(int k, int n) {
    LL r = 1;
    Rep(i, k) r = r * (n - i) % mod;
    For(i, 1, k) r = r * p2[i] % mod;
    return r;
}

int calc(int i, int d) {
    if (d == 0) return 0;
    if (a[i].size() == 0) {
        return d;
    }
    int &res = F[i][d];
    if (res != -1) return res;
    res = calc(i, d - 1);
    LL x = 1;
    Rep(k, a[i].size()) {
        int j = a[i][k];
        x = x * calc(j, d) % mod;
    }
    res = (res + x) % mod;
    return res;
}

int main() {
    cin >> n >> D;
    For(i, 1, n-1) {
        int x;
        cin >> x;
        --x;
        a[x].pb(i);
    }
    For(i, 0, n) p2[i] = PP(i, mod - 2);
    For(i, 0, n) For(j, i, n) {
        if (i == 0 || i == j) C[i][j] = 1;
        else C[i][j] = (C[i][j - 1] + C[i - 1][j - 1]) % mod;
    }
    // cout << C[1][3] << " " << C[2][3] << endl;
    LL res = 0;
    memset(F, -1, sizeof(F));
    // cout << calc(0, 1) << " " << calc(0, 2) << " " << calc(0, 3) << endl;
    For(d, 1, n) if (d <= D) {
        G[d] = calc(0, d);
        For(d2, 1, d-1) {
            G[d] = ((G[d] - G[d2] * 1LL * C[d2][d]) % mod + mod) % mod;
        }
        // cout << G[d] << endl;
        res = (res + G[d] * 1LL * CC(d, D)) % mod;
    }
    cout << res << endl;
    return 0;
}