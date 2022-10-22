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

#include <conio.h>

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
const LL MOD = inf + 9;
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

LL binpow(LL n, LL m) {
    if(m == 0) return 1ll;
    LL q = binpow(n, m / 2);
    q = (q * q) % base;
    if(m % 2) {
        return (q * n) % base;
    }else{
        return q;
    }
}

LL R(LL x) {
    return binpow(x, base - 2);
}

LL S(LL a, LL n, LL k) {
    LL q = binpow(2ll, n);
    LL b0 = binpow(2ll, a);
    LL val = binpow(q, k);val--;
    val = (val % base + base) % base;
    val = (val * b0) % base;
    q--;
    q = (q % base + base) % base;
    q = R(q);
    return (q * val) % base;
}

bool solve()
{
    string a;
    cin >> a;

    int k;
    scanf("%d", &k);

    LL ans = 0;

    for(int i(0);i < (int)a.size();i++) {
        if(a[i] == '0' || a[i] == '5') {
            ans = (ans + S(i, (int)a.size(), k)) % base;
        }
    }

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}