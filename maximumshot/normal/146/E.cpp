#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
  
using namespace std;
  
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector
#define go(x, y) q.push(mp((x), (y))), ans[(x)][(y)] = 1;
  
typedef long long LL;
typedef long double LD;
  
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;    

LL binpow(LL n, LL m)
{
    if(m == 0) return 1ll;

    LL q = binpow(n, m / 2);
    q = (q * q) % base;

    if(m % 2) return (q * n) % base;
    else return q;
}

vec<LL> get_around(LL m, int size = 123456)
{
    vec<LL> r(size, 0);
    r[1] = 1;
    r[0] = 1;
    for(LL i(2);i < size;i++)
    {
        r[i] = -r[m % i] * (m / i);
        r[i] = (m + r[i] % m) % m;
    }

    //  :
    //  : m % i == m - (m / i) * i
    //      m (m % m == 0)
    // (m % i) % m == (-(m / i) * i) % m
    //   r[m % i] : (r[m % i] * (m % i) % m == 1)
    // 1 % m == (-r[m % i] * (m / i) * i) % m
    //   r[i] : (r[i] * i % m == 1)
    // r[i] % m == (-r[m % i] * (m / i)) % m
    // r[i] ( ) -r[m % i] * (m / i)   m

    return r;
}

LL R(LL x)
{
    return binpow(x, base - 2);
}

vec< vec<LL> > C;
vec<LL> a, r, C2, fact;
LL b = 0;
int n, k;

bool is_lucky(LL x)
{
    if(!x) return 0;
    while(x)
    {
        if(x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }

    return true;
}

void make()
{
    fact.resize(1e5 + 10, 0);
    fact[0] = 1ll;
    for(LL i(1);i < 1e5 + 10;i++) fact[i] = (fact[i - 1] * i) % base;
    C2.resize(b + 1);
    for(int i(0);i <= b;i++)
    {
        LL mn1, mn2, mn3;
        mn1 = fact[b];
        mn2 = R(fact[b - i]);
        mn3 = R(fact[i]);
        C2[i] = ((mn1 * mn2) % base) * mn3 % base;
    }

    set<LL> s;
    for(auto i : a) s.insert(i);
    s.erase(-inf64);
    
    sort(ALL(a));
    vec<LL> tmp;
    int pos = 1;
    bool flag = ((int)s.size() == (int)a.size() - 1);
    for(auto i : s)
    {
        int count = 0;
        while(pos < (int)a.size() && a[pos] == i) count++, pos++;
        tmp.push_back(count);
    }

    a.clear();
    a = tmp;
    tmp.clear();

    int sz = (int)a.size();

    C.resize(sz + 1, vec<LL>(sz + 1, 0));
    C[0][0] = 1;
    LL mnow = 1;
    for(int i(1);i <= sz;i++)
    {
        mnow *= a[i - 1];
        mnow %= base;
        C[i][0] = 1;
        C[i][i] = mnow;
        for(int j(1);j < i;j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1] * a[i - 1] % base) % base;
    }
}

bool solve()
{
    scanf("%d %d", &n, &k);

    r = get_around(base);   
    
    a.push_back(-inf64);
    for(int i(0);i < n;i++)
    {
        LL x;
        scanf("%I64d", &x);
        if(is_lucky(x)) a.push_back(x);
        else b++;
    }

    make();

    LL ans = 0;

    for(int x(0);x <= k;x++)
    {
        if(x > b || k - x > (int)a.size()) continue;
        ans += C2[x] * C[(int)a.size()][k - x] % base;
        ans %= base;
    }

    printf("%I64d\n", ans);

    return true;    
}
  
int main()
{
    //while(solve());
    solve();
  
    return 0;
}