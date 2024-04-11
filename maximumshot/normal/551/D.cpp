#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

vec< vec<LL> > mul(const vec< vec<LL> > & a, const vec< vec<LL> > & b, LL MOD) {
    int n = (int)a.size();
    int m = (int)b[0].size();
    int l = (int)b.size();
    vec< vec<LL> > ans(n, vec<LL>(m));
    for(int i(0);i < n;i++) {
        for(int j(0);j < m;j++) {
            for(int q(0);q < l;q++) {
                ans[i][j] = (ans[i][j] + a[i][q] * b[q][j] % MOD) % MOD;
            }
        }   
    }
    return ans;
}

vec< vec<LL> > binpow(vec< vec<LL> > n, LL m, LL MOD)
{
    if(m == 0) {
        vec< vec<LL> > ans(2, vec<LL>(2));
        ans[0][0] = ans[1][1] = 1 % MOD;
        return ans;
    }

    vec< vec<LL> > q = binpow(n, m / 2, MOD);
    q = mul(q, q, MOD);

    if(m % 2) return mul(q, n, MOD);
    else return q;
}

LL fib(LL n, LL MOD) { // return Fn % MOD
    if(n == 0) return 0;
    else if(n == 1 || n == 2) return 1 % MOD;
    vec< vec<LL> > mat(2, vec<LL>(2)), mat2(2, vec<LL>(1));
    mat[0][0] = mat[0][1] = mat[1][0] = 1;
    mat = binpow(mat, n, MOD);
    mat2[0][0] = 1 % MOD;
    mat = mul(mat, mat2, MOD);
    return mat[1][0];
}

LL bp(LL m, LL MOD) {
    if(m == 0) return 1ll % MOD;
    LL q = bp(m / 2, MOD);
    q = (q * q) % MOD;
    if(m % 2) return (q * 2ull) % MOD;
    else return q;
}

bool solve()
{
    LL n, k, l, m;

    cin >> n >> k >> l >> m;

    if(l <= 62 && (1ll << l) <= k) {
        puts("0");
        return true;
    }

    LL ans0 = fib(n + 2, m);
    LL ans1 = bp(n, m) - ans0;
    ans1 = (ans1 % m + m) % m;

    LL ans = 1 % m;

    LL c1 = 0, c0 = 0;

    for(LL i(0);(1ll << i) <= k;i++) {
        if((1ll << i) & k) c1++;
    }

    c0 = l - c1;



    for(int i(0);i < c0;i++) ans = (ans * ans0) % m;
    for(int i(0);i < c1;i++) ans = (ans * ans1) % m;

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}