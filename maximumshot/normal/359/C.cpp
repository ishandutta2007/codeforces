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

LL binpow(LL n, LL m) {
    if(m == 0) return 1ll % base;
    LL q = binpow(n, m / 2);
    q = (q * q) % base;
    return (m % 2?(q * n) % base : q);
}

bool solve()
{       
    int n;
    LL x, sum = 0;
    cin >> n >> x;

    vec< LL > a(n), b;
    for(int i = 0;i < n;i++) cin >> a[i], sum += a[i];
    for(int i = 0;i < n;i++) {
        b.push_back(sum - a[i]);    
    }

    sort(ALL(b));

    map< LL, LL > m;
    for(int i = 0;i < n;i++) m[b[i]]++;

    while(1) {
        LL k, c;
        k = m.begin()->first;
        c = m.begin()->second;
        if(c % x) break;
        m.erase(k);
        while(c % x == 0) {
            c /= x;k++;
        }
        m[k] += c;
    }

    LL p = min(sum, m.begin()->first);

    cout << binpow(x, p) << '\n';

    return true;
}  

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}