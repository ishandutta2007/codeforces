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
#include <cstring>

//#include <conio.h>

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

const int NMAX = 200200;

LL fact[NMAX], rfact[NMAX];

// n ^ m
LL binpow(LL n, LL m) {
    if(m == 0) return 1ll;
    LL q = binpow(n, m / 2);
    q = (q * q) % base;
    if(m % 2) return (q * n) % base;
    else return q;
}

LL R(LL x) {
    return binpow(x, base - 2);
}

LL C(LL n, LL k) {
    return (n < k?0 : ((fact[n] * rfact[n - k] % base) * rfact[k] % base));
} 

bool solve()
{      
    fact[0] = 1ll;
    rfact[0] = R(fact[0]);
    for(LL i = 1;i < NMAX;i++) {
        fact[i] = (fact[i -1] * i) % base;
        rfact[i] = R(fact[i]);
    }

    int w, h, n;    

    scanf("%d %d %d", &h, &w, &n);

    vec< pair< int, int> > a(n); 
    for(int x, y, i(0);i < n;i++) {
        scanf("%d %d", &x, &y);
        a[i] = mp(x, y);
    }

    sort(ALL(a));
    a.push_back(mp(h, w));

    vec< LL > dp(n + 1);

    for(int i = 0;i <= n;i++) {
        int I, J;
        I = a[i].first - 1;
        J = a[i].second - 1;
        dp[i] = C(I + J, I);
        for(int j = 0;j < i;j++) {
            if(a[j].first <= a[i].first && a[j].second <= a[i].second) {
                int d1, d2;
                d1 = a[i].first - a[j].first;
                d2 = a[i].second - a[j].second;
                dp[i] -= C(d1 + d2, d1) * dp[j];
                dp[i] = (dp[i] % base + base) % base;
            }
        }
    }

    cout << dp[n] << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}