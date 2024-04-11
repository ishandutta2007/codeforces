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
#define Foreach(i,c) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }

const int mod = 1000000007;
long long fact[200020];

int n;
long long a[200020];
long long newa[200020];

long long P(long long x, int y) {
    if (y == 0) return 1;
    else {
        long long a = P(x, y / 2);
        if (y % 2 == 0) return (a * a) % mod;
        else return (a * a) % mod * x % mod;
    }
}

long long F(int k, int n) {
    long long res = fact[n];
    res = res * P(fact[k], mod - 2) % mod;
    res = res * P(fact[n-k], mod - 2) % mod;
    return res;
}


int main() {
    cout.sync_with_stdio(false);
    cin >> n;
    Rep(i, n) cin >> a[i];
    Rep(i, n) a[i] = (a[i] % mod + mod) % mod;

    fact[0] = 1;
    For(i, 1, n) fact[i] = (fact[i - 1] * i) % mod;

    bool add = true;

    while (n % 4 != 1) {
        memset(newa, 0, sizeof(newa));
        Rep(i, n - 1) {
            if (add) {
                newa[i] = a[i] + a[i + 1];
            } else {
                newa[i] = a[i] - a[i + 1];
            }
            add = !add;
        }
        Rep(i, n) a[i] = (newa[i] % mod + mod) % mod;
        --n;
    }

    int k = n / 4;
    int m = 2 * k;

    long long res = 0;

    Rep(i, n) {
        if (i % 2 != 0) {}
        else {
            long long t = a[i] * F(i / 2, m) % mod;
            res = ((res + t) % mod + mod) % mod;
        }
    }

    res = (res % mod + mod) % mod;
    cout << res << endl;
    
    return 0;
}